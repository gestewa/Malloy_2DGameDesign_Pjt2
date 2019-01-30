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
  SDL_Rect dst = {40, HEIGHT - 40, textWidth, textHeight};

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

    SDL_SetRenderDrawColor(renderer, color_palette["white"].r, color_palette["white"].g, color_palette["white"].b, 255);
    SDL_RenderClear(renderer);

    // Overall Head Shape
    Rectangle(Point(28, 0), 768, 720, color_palette["dark_brown"]).Draw(renderer);
    Rectangle(Point(28, 0), 768, 480, color_palette["light_brown_head"]).Draw(renderer);

    // Light Nose Part
    Rectangle(Point(162, 146), 511, 278, color_palette["light_brown_nose"]).Draw(renderer);

    //Dark Nose Part
    Rectangle(Point(305, 146), 224, 134, color_palette["dark_brown"]).Draw(renderer);
    Rectangle(Point(408.3, 146), 10, 309, color_palette["dark_brown"]).Draw(renderer);

    // Head Shape
    Triangle(Point(415, 0), Point(830, 0), Point(830, 100), color_palette["white"]).Draw(renderer);
    Triangle(Point(415, 0), Point(0, 0), Point(0, 100), color_palette["white"]).Draw(renderer);
    Triangle(Point(156, 0), Point(0, 0), Point(0, 584), color_palette["white"]).Draw(renderer);
    Triangle(Point(674, 0), Point(830, 0), Point(830, 614), color_palette["white"]).Draw(renderer);

    // Face Shape (Chin)
    Triangle(Point(29, 480), Point(794, 480), Point(413, 570), color_palette["light_brown_head"]).Draw(renderer);

    // Nose Shape
    Triangle(Point(161, 145), Point(161 + 106, 145), Point(161, 145 + 288), color_palette["light_brown_head"]).Draw(renderer);
    Triangle(Point(568, 146), Point(568 + 106, 146), Point(568 + 106, 146 + 288), color_palette["light_brown_head"]).Draw(renderer);
    Triangle(Point(166, 424), Point(504 + 166, 424), Point(415, 54 + 424), color_palette["dark_brown"]).Draw(renderer);
    Triangle(Point(306, 280), Point(526, 280), Point(415, 324), color_palette["dark_brown"]).Draw(renderer);
    Triangle(Point(159, 151), Point(159 + 256, 151), Point(159, 151 + 28), color_palette["light_brown_head"]).Draw(renderer);
    Triangle(Point(415, 151), Point(415 + 256, 151), Point(415 + 256, 151 + 28), color_palette["light_brown_head"]).Draw(renderer);
    Triangle(Point(138, 140), Point(508, 140), Point(138, 181), color_palette["light_brown_head"]).Draw(renderer);
    Triangle(Point(334, 141), Point(704, 142), Point(704, 182), color_palette["light_brown_head"]).Draw(renderer);

    // Teeth
    Rectangle(Point(365.4, 424), 43, 31, color_palette["yellowish"]).Draw(renderer);
    Rectangle(Point(418.3, 424), 43, 31, color_palette["yellowish"]).Draw(renderer);

    // Eyes
    Circle(Point(230, 146), 24, color_palette["dark_brown"]).Draw(renderer);
    Circle(Point(607, 146), 24, color_palette["dark_brown"]).Draw(renderer);

    // Whiskers Right Side
    Line(Point(481.5, 340), Point(826, 435), color_palette["black"]).Draw(renderer);
    Line(Point(480.5, 339), Point(825, 434), color_palette["black"]).Draw(renderer);
    Line(Point(480.5, 339), Point(825, 433), color_palette["black"]).Draw(renderer);
    Line(Point(481.5, 339), Point(820, 339), color_palette["black"]).Draw(renderer);
    Line(Point(481.5, 340), Point(820, 340), color_palette["black"]).Draw(renderer);
    Line(Point(481.5, 340), Point(783, 502), color_palette["black"]).Draw(renderer);
    Line(Point(482.5, 340), Point(784, 502), color_palette["black"]).Draw(renderer);
    Line(Point(483.5, 340), Point(785, 502), color_palette["black"]).Draw(renderer);
    Line(Point(481.5, 340), Point(731, 570), color_palette["black"]).Draw(renderer);
    Line(Point(482.5, 340), Point(732, 570), color_palette["black"]).Draw(renderer);
    Line(Point(480.5, 340), Point(730, 570), color_palette["black"]).Draw(renderer);

    // Whiskers Left Side
    Line(Point(340, 340), Point(8, 340), color_palette["black"]).Draw(renderer);
    Line(Point(340, 339), Point(8, 339), color_palette["black"]).Draw(renderer);
    Line(Point(340, 340), Point(10, 436), color_palette["black"]).Draw(renderer);
    Line(Point(340, 339), Point(10, 435), color_palette["black"]).Draw(renderer);
    Line(Point(340, 339), Point(10, 434), color_palette["black"]).Draw(renderer);
    Line(Point(340, 340), Point(40, 502), color_palette["black"]).Draw(renderer);
    Line(Point(340, 340), Point(40, 501), color_palette["black"]).Draw(renderer);
    Line(Point(340, 339), Point(40, 500), color_palette["black"]).Draw(renderer);
    Line(Point(340, 340), Point(95, 572), color_palette["black"]).Draw(renderer);
    Line(Point(340, 339), Point(95, 571), color_palette["black"]).Draw(renderer);
    Line(Point(340, 339), Point(95, 570), color_palette["black"]).Draw(renderer);

    // Ears
    Triangle(Point(140, 68), Point(110, 180), Point(46, 178), color_palette["light_brown_ears"]).Draw(renderer);
    Triangle(Point(690, 68), Point(719, 180), Point(788, 178), color_palette["light_brown_ears"]).Draw(renderer);

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
