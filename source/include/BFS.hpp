#pragma once

#include <iostream>
#include <queue>
#include <unordered_set>
#include "global.hpp"


std::vector<Coords> get_neighbors(Coords current, const Grid &grid);
void run_bfs(Grid&, Coords&, Coords&);
