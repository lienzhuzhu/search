#include <chrono>
#include <iostream>

#include "include/BFS.hpp"
#include "include/DrawMap.hpp"
#include "include/HandleMouse.hpp"


int main()
{
    sf::RenderWindow window(sf::VideoMode(CELL_SIZE * MAP_COLS, CELL_SIZE * MAP_ROWS), "Artificial Intelligence finds its path...");

    Grid map;
    init_map(map);

    sf::Clock clock;
    float delta_time = 0.0f;

    Coords start, goal;
    Coords prev_start, prev_goal;
    bool start_set = false, goal_set = false;

    bool search_completed = false;

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
                if (start_set) {
                    map[prev_start.second][prev_start.first].setFillColor(GRAY);
                }
                start = get_mouse_cell(window);
                map[start.second][start.first].setFillColor(RED);
                
                prev_start = start;
                start_set = true;
                search_completed = false;
            }
            else {
                if (goal_set) {
                    map[prev_goal.second][prev_goal.first].setFillColor(GRAY);
                }
                goal = get_mouse_cell(window);
                map[goal.second][goal.first].setFillColor(YELLOW);
                prev_goal = goal;
                goal_set = true;
                search_completed = false;
            }
        }
        
        if (start_set && goal_set && !search_completed) {
            reset_map(map, window, start, goal);
            if (start != goal) {
                run_bfs(map, start, goal);
            }
            search_completed = true;
        }

        window.clear();

        draw_map(map, window);

        window.display();
    }

    return 0;
}

