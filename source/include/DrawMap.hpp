#pragma once

#include "global.hpp"


void init_map(Grid&);
void draw_map(Grid&, sf::RenderWindow&);
void reset_map(Grid&, sf::RenderWindow&, Coords&, Coords&, std::queue<Coords>&, ParentMap&);
