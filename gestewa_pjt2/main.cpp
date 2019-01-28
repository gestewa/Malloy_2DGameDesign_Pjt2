#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "frameGenerator.h"
#include "circle.h"
#include "line.h"
#include "point.h"
#include "rectangle.h"
#include "triangle.h"
#include "colors.h"

const std::string TITLE = "Gabrielle Stewart's Beaver";
const std::string NAME = "gestewa";

const int WIDTH = 830;
const int HEIGHT = 720;

void writeName(SDL_Renderer *renderer)
{
  TTF_Init();
  TTF_Font *font = TTF_OpenFont("fonts/arial.ttf", 24);
  if (font == NULL)
  {
    throw std::string("error: font not found");
  }
  SDL_Color textColor = {0xff, 0, 0, 0};
  SDL_Surface *surface =
      TTF_RenderText_Solid(font, TITLE.c_str(), textColor);
  SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);

  int textWidth = surface->w;
  int textHeight = surface->h;
  SDL_FreeSurface(surface);
  SDL_Rect dst = {20, HEIGHT - 40, textWidth, textHeight};

  SDL_RenderCopy(renderer, texture, NULL, &dst);
  SDL_DestroyTexture(texture);
}

int main(void)
{
  try
  {
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
      std::cout << "Failed to initialize SDL2" << std::endl;
      return EXIT_FAILURE;
    }
    SDL_Window *window = SDL_CreateWindow(
        TITLE.c_str(),
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        WIDTH,
        HEIGHT,
        SDL_WINDOW_SHOWN);
    // Apparently we can't use hardware acceleration with
    // SDL_GetWindowSurface
    SDL_Renderer *renderer = SDL_CreateRenderer(
        window, -1, SDL_RENDERER_SOFTWARE);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);

    // TODO, call proper functions
    // Overall Head Shape
    Rectangle(Point(30, 0), 770, 720, color_palette["dark_brown"]).Draw(renderer);
    Rectangle(Point(30, 0), 770, 480, color_palette["light_brown_head"]).Draw(renderer);

    // Light Nose Part
    Rectangle(Point(160.5, 165), 504, 259, color_palette["light_brown_nose"]).Draw(renderer);

    //Dark Nose Part
    Rectangle(Point(301.5, 158.5), 223, 118, color_palette["dark_brown"]).Draw(renderer);
    Rectangle(Point(408.3, 317.5), 10, 138, color_palette["dark_brown"]).Draw(renderer);

    // Teeth
    Rectangle(Point(365.4, 424), 42.9, 31, color_palette["yellowish"]).Draw(renderer);
    Rectangle(Point(418.3, 424), 42.9, 31, color_palette["yellowish"]).Draw(renderer);

    writeName(renderer);
    SDL_RenderPresent(renderer);
    FrameGenerator frameGen(renderer, window, WIDTH, HEIGHT, NAME);
    frameGen.makeFrame();

    SDL_Event event;
    const Uint8 *keystate;
    while (true)
    {
      keystate = SDL_GetKeyboardState(0);
      if (keystate[SDL_SCANCODE_ESCAPE])
      {
        break;
      }
      if (SDL_PollEvent(&event))
      {
        if (event.type == SDL_QUIT)
        {
          break;
        }
      }
    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
  }
  catch (const std::string &msg)
  {
    std::cout << msg << std::endl;
  }
  catch (...)
  {
    std::cout << "Oops, someone threw an exception!" << std::endl;
  }
  return EXIT_SUCCESS;
}
