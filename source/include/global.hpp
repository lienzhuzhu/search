#pragma once

#include <SFML/Graphics.hpp>
#include <queue>
#include <iostream>
#include <unordered_set>

#define MAP_ROWS 40
#define MAP_COLS 60
#define CELL_SIZE 25

#define X 0
#define Y 1

#define BLACK sf::Color(4,4,3)
#define GRAY sf::Color(93,115,126)
#define YELLOW sf::Color(255,240,124)
#define WHITE sf::Color(240,247,238)
#define RED sf::Color(255,102,99)
#define BLUE sf::Color(0,109,170)

enum class State {
    EMPTY = 0,
    VISITED,
    START,
    GOAL,
    PATH,
    WALL
};

using GridSquares = std::array<std::array<State, MAP_ROWS>, MAP_COLS>;
using Coords = std::array<unsigned int, 2>;
using ParentMap = std::map<Coords, Coords>;

constexpr unsigned short STEPS_PER_FRAME = 8;

enum SearchStatus {
    NOT_STARTED_YET = 0,
    SEARCH_COMPLETED,
    SEARCH_IN_PROGRESS
};
