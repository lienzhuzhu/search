#include <chrono>
#include <iostream>

#include "include/BFS.hpp"
#include "include/DrawMap.hpp"
#include "include/HandleMouse.hpp"


int main() {
    sf::RenderWindow window(sf::VideoMode(CELL_SIZE * MAP_COLS, CELL_SIZE * MAP_ROWS), "Artificial Intelligence finds its path...", sf::Style::Titlebar | sf::Style::Close);

    Grid map;
    init_map(map);

    Coords start, goal, wall_cell;
    Coords prev_start, prev_goal;
    bool start_set = false, goal_set = false;

    SearchStatus search_status = NOT_STARTED_YET;

    std::queue<Coords> coords_q;
    ParentMap parents;

    sf::Clock clock;
    const float dt = 1.0f / 60.0f; // Fixed timestep in seconds
    float last_timestamp = dt;  // Stores when the next update should happen


    while (window.isOpen()) {

        sf::Event event;
        while (window.pollEvent(event))
        {
            switch(event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::MouseButtonReleased:
                    search_status = SEARCH_IN_PROGRESS;
                default:
                    break;
            }
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) || sf::Mouse::isButtonPressed(sf::Mouse::Button::Right)) {
            if (mouse_is_in_bounds(window)) {
                if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
                        wall_cell = get_mouse_cell(window);
                        if (wall_cell != start || wall_cell != goal) {
                            map[wall_cell.second][wall_cell.first].setFillColor(BLACK);
                        }
                    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
                        wall_cell = get_mouse_cell(window);
                        if (wall_cell != start || wall_cell != goal) {
                            map[wall_cell.second][wall_cell.first].setFillColor(GRAY);
                        }
                    } else {
                        if (start_set) {
                            map[prev_start.second][prev_start.first].setFillColor(GRAY);
                        }
                        start = get_mouse_cell(window);
                        map[start.second][start.first].setFillColor(RED);
                        
                        prev_start = start;
                        start_set = true;
                    }
                } else {
                    if (goal_set) {
                        map[prev_goal.second][prev_goal.first].setFillColor(GRAY);
                    }
                    goal = get_mouse_cell(window);
                    map[goal.second][goal.first].setFillColor(YELLOW);
                    prev_goal = goal;
                    goal_set = true;
                }
                search_status = NOT_STARTED_YET;
            }
        }

        
        float current_time = clock.getElapsedTime().asSeconds(); // Get the current time
        if (current_time >= last_timestamp) {

            last_timestamp += dt;

            if (start_set && goal_set) {
                if (search_status == NOT_STARTED_YET) {
                    reset_map(map, window, start, goal, coords_q, parents);
                }
                
                if (search_status == SEARCH_IN_PROGRESS) {
                    if (start != goal) {
                        search_status = run_bfs(map, start, goal, coords_q, parents);
                    }
                }
            }
        }

        window.clear();
        draw_map(map, window);
        window.display();
    }

    return 0;
}

