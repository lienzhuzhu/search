#include "include/Map.hpp"


void init_map(Grid& map) {
    for (int row_i = 0; row_i < MAP_ROWS; ++row_i) {
        for (int col_i = 0; col_i < MAP_COLS; ++col_i) {
            sf::RectangleShape& curr_cell = map[row_i][col_i];
            curr_cell.setSize(sf::Vector2f(CELL_SIZE, CELL_SIZE));
            curr_cell.setPosition( sf::Vector2f(col_i * CELL_SIZE, row_i * CELL_SIZE) );
            curr_cell.setOutlineColor(BLACK);
            curr_cell.setOutlineThickness(5.f);
            if (curr_cell.getFillColor() != BLACK) {
                curr_cell.setFillColor(GRAY);
            }
        }
    }
}

void draw_map(Grid& map, sf::RenderWindow& window) {
    for (int row_i = 0; row_i < MAP_ROWS; ++row_i) {
        for (int col_i = 0; col_i < MAP_COLS; ++col_i) {
            window.draw(map[row_i][col_i]);
        }
    }
}

void reset_map(Grid& map, sf::RenderWindow& window, Coords& start, Coords& goal, std::queue<Coords>& coords_q, ParentMap& parents) {
    init_map(map);
    map[start.second][start.first].setFillColor(RED);
    map[goal.second][goal.first].setFillColor(YELLOW);
    std::queue<Coords> empty_q;
    coords_q.swap(empty_q);
    parents.clear();
    coords_q.push(start);
}
