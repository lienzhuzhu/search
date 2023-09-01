#include "include/HandleMouse.hpp"


Coords get_mouse_cell(const sf::RenderWindow& window) {
    float mouse_x = sf::Mouse::getPosition(window).x;
    float mouse_y = sf::Mouse::getPosition(window).y;

    return Coords(floor(mouse_x / CELL_SIZE), floor(mouse_y / CELL_SIZE));
}
