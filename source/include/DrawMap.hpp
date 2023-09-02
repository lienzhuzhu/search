#pragma once

#include "global.hpp"


Grid init_map();
void draw_map(Grid&, sf::RenderWindow&);
void reset_map(Grid&, sf::RenderWindow&, Coords&, Coords&);
