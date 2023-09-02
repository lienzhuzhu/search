#include "include/global.hpp"

bool is_wall_cell(Grid& map, Coords& cell) {
    return map[cell.second][cell.first].getFillColor() == BLACK;
}
