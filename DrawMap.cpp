#include "include/DrawMap.hpp"


Grid init_map() {
    std::array<std::array<sf::RectangleShape, MAP_COLS>, MAP_ROWS> map;
    for (int row_i = 0; row_i < MAP_ROWS; ++row_i) {
        for (int col_i = 0; col_i < MAP_COLS; ++col_i) {
            sf::RectangleShape& curr_cell = map[row_i][col_i];
            curr_cell.setSize(sf::Vector2f(CELL_SIZE, CELL_SIZE));
            curr_cell.setPosition( sf::Vector2f(col_i * CELL_SIZE, row_i * CELL_SIZE) );
            curr_cell.setOutlineColor(BLACK);
            curr_cell.setOutlineThickness(5.f);
            curr_cell.setFillColor(GRAY);
        }
    }

    return map;
}

void draw_map(Grid& map, sf::RenderWindow& window) {
    for (int row_i = 0; row_i < MAP_ROWS; ++row_i) {
        for (int col_i = 0; col_i < MAP_COLS; ++col_i) {
            window.draw(map[row_i][col_i]);
        }
    }
}
