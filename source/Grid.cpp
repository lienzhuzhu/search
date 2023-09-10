#include "include/Grid.hpp"


Grid::Grid(sf::RenderWindow &window) : window_(window) {
    for (int col_i = 0; col_i < MAP_COLS; ++col_i) {
        for (int row_i = 0; row_i < MAP_ROWS; ++row_i) {
            grid_[col_i][row_i] = State::EMPTY;
        }
    }
}


void Grid::draw() {
    State curr_square;

    for (int col_i = 0; col_i < MAP_COLS; ++col_i) {
        for (int row_i = 0; row_i < MAP_ROWS; ++row_i) {

            curr_square = grid_[col_i][row_i];

            sf::RectangleShape curr_cell;
            curr_cell.setSize(sf::Vector2f(CELL_SIZE, CELL_SIZE));
            curr_cell.setPosition( sf::Vector2f(col_i * CELL_SIZE, row_i * CELL_SIZE) );
            curr_cell.setOutlineColor(BLACK);
            curr_cell.setOutlineThickness(5.f);

            switch(curr_square) {
                case State::EMPTY:
                    curr_cell.setFillColor(GRAY);
                    break;
                case State::VISITED:
                    curr_cell.setFillColor(WHITE);
                    break;
                case State::START:
                    curr_cell.setFillColor(RED);
                    break;
                case State::GOAL:
                    curr_cell.setFillColor(YELLOW);
                    break;
                case State::PATH:
                    curr_cell.setFillColor(BLUE);
                    break;
                case State::WALL:
                    curr_cell.setFillColor(BLACK);
                    break;
                default:
                    break;
            }

            window_.draw(curr_cell);
        }
    }
}


void Grid::reset() {
    for (int col_i = 0; col_i < MAP_COLS; ++col_i) {
        for (int row_i = 0; row_i < MAP_ROWS; ++row_i) {
            if (grid_[col_i][row_i] != State::WALL) {
                grid_[col_i][row_i] = State::EMPTY;
            }
        }
    }
}


void Grid::set_state(Coords &cell, State state) {
    grid_[cell[X]][cell[Y]] = state;
}


State Grid::get_state(Coords &cell) {
    return grid_[cell[X]][cell[Y]];
}


bool Grid::cell_is_wall(Coords &cell) {
    return grid_[cell[X]][cell[Y]] == State::WALL;
}
