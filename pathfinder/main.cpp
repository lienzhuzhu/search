#include <chrono>
#include <iostream>

#include "include/BFS.hpp"
#include "include/DrawMap.hpp"
#include "include/HandleMouse.hpp"


int main()
{
    sf::RenderWindow window(sf::VideoMode(CELL_SIZE * MAP_COLS, CELL_SIZE * MAP_ROWS), "Artificial Intelligence finds its path...");

    Grid map = init_map();

    sf::Clock clock;
    float delta_time = 0.0f;

    while (window.isOpen())
    {
        delta_time = clock.restart().asSeconds();

        // Event handling
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch(event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                default:
                    break;
            }
        }

        Coords start;
        Coords goal;
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) || sf::Mouse::isButtonPressed(sf::Mouse::Button::Right)) {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
                start = get_mouse_cell(window);
                std::cout << "start: " << start.first << " " << start.second << std::endl;
                map[start.second][start.first].setFillColor(RED);
            }
            else {
                goal = get_mouse_cell(window);
                std::cout << "goal: " << goal.first << " " << goal.second << std::endl;
                map[goal.second][goal.first].setFillColor(YELLOW);
            }
        }

        window.clear();

        draw_map(map, window);

        window.display();
    }

    return 0;
}

