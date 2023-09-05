#include "include/HandleMouse.hpp"


Coords get_mouse_cell(const sf::RenderWindow& window) {
    float mouse_x = sf::Mouse::getPosition(window).x;
    float mouse_y = sf::Mouse::getPosition(window).y;

    return Coords(floor(mouse_x / CELL_SIZE), floor(mouse_y / CELL_SIZE));
}

bool mouse_is_in_bounds(const sf::RenderWindow& window) {
    sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
    return (mouse_pos.x >= 0 && mouse_pos.x <= window.getSize().x && mouse_pos.y >= 0 && mouse_pos.y <= window.getSize().y);
}
