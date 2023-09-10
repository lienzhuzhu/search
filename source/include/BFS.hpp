#pragma once

#include "global.hpp"
#include "Grid.hpp"


std::vector<Coords> get_neighbors(Coords &current);
SearchStatus run_bfs(Grid &grid, Coords &start, Coords &goal, std::queue<Coords> &coords_q, ParentMap &parents);
void reset_bfs(Grid &grid, Coords &start, Coords &goal, std::queue<Coords> &coords_q, ParentMap &parents);
