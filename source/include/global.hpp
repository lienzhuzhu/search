#pragma once

#include <SFML/Graphics.hpp>
#include <queue>

#define MAP_ROWS 40
#define MAP_COLS 60
#define CELL_SIZE 25

#define BLACK sf::Color(4,4,3)
#define GRAY sf::Color(93,115,126)
#define YELLOW sf::Color(255,240,124)
#define WHITE sf::Color(240,247,238)
#define RED sf::Color(255,102,99)
#define BLUE sf::Color(0,109,170)

using Grid = std::array<std::array<sf::RectangleShape, MAP_COLS>, MAP_ROWS>;
using Coords = std::pair<unsigned short, unsigned short>;
using ParentMap = std::map<Coords, Coords>;

bool cell_is_wall(Grid&, Coords&);

constexpr unsigned short STEPS_PER_FRAME = 8;

enum SearchStatus {
    NOT_STARTED_YET = 0,
    SEARCH_COMPLETED,
    SEARCH_IN_PROGRESS
};
