#pragma once

#include <iostream>
#include <unordered_set>
#include "global.hpp"


std::vector<Coords> get_neighbors(Coords current, const Grid &grid);
void run_bfs(Grid& map, Coords& start, Coords& goal, std::queue<Coords>& coords_q, ParentMap& parents);
