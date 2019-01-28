#pragma once

#include <unordered_map>
#include <SDL2/SDL.h>

std::unordered_map<std::string, SDL_Color> color_palette = {
    {"dark_brown", {88, 53, 31, 255}},
    {"light_brown_ears", {186, 117, 44, 255}},
    {"yellowish", {255, 196, 65, 255}},
    {"black", {30, 30, 30, 255}},
    {"light_brown_nose", {198, 146, 81, 255}},
    {"light_brown_head", {148, 99, 45, 255}},
    {"white", {255, 255, 255, 255}}};
