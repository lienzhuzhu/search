#include "include/global.hpp"

bool cell_is_wall(Grid& map, Coords& cell) {
    return map[cell.second][cell.first].getFillColor() == BLACK;
}
