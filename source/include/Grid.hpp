#pragma once

#include "global.hpp"


class Grid {
public:
    Grid(sf::RenderWindow& window);
    void draw();
    void reset();
    void set_state(Coords&, State);
    State get_state(Coords&);
    bool cell_is_wall(Coords&);

private:
    sf::RenderWindow& window_;
    GridSquares grid_;
};
