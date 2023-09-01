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

    Coords start, goal;
    Coords prev_start, prev_goal;
    bool prev_start_set = false, prev_goal_set = false;

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

        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) || sf::Mouse::isButtonPressed(sf::Mouse::Button::Right)) {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
                // Step 1: Check if this is not first setting
                if (prev_start_set) {
                    map[prev_start.second][prev_start.first].setFillColor(GRAY);
                }
                // Step 2: Get new start.
                start = get_mouse_cell(window);
                
                // Step 3: Set new start cell to red.
                map[start.second][start.first].setFillColor(RED);
                
                // Step 4: Update prev_start.
                prev_start = start;
                prev_start_set = true;
            }
            else {
                if (prev_goal_set) {
                    map[prev_goal.second][prev_goal.first].setFillColor(GRAY);
                }
                goal = get_mouse_cell(window);
                map[goal.second][goal.first].setFillColor(YELLOW);
                prev_goal = goal;
                prev_goal_set = true;
            }
        }
        

        window.clear();

        draw_map(map, window);

        window.display();
    }

    return 0;
}

