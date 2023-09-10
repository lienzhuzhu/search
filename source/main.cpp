#include <chrono>

#include "include/BFS.hpp"
#include "include/Grid.hpp"
#include "include/HandleMouse.hpp"


int main() {
    sf::RenderWindow window(sf::VideoMode(CELL_SIZE * MAP_COLS, CELL_SIZE * MAP_ROWS), "Artificial Intelligence finds its path...", sf::Style::Titlebar | sf::Style::Close);

    Grid search_grid(window);

    Coords start, goal, wall_cell;
    Coords prev_start, prev_goal;
    bool start_set = false, goal_set = false;
    SearchStatus search_status = NOT_STARTED_YET;

    std::queue<Coords> coords_q;
    ParentMap parents;

    sf::Clock clock;
    const float dt = 1.0f / 60.0f;
    float last_timestamp = dt;


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
                            search_grid.set_state(wall_cell, State::WALL);
                        }
                    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
                        wall_cell = get_mouse_cell(window);
                        if (wall_cell != start || wall_cell != goal) {
                            search_grid.set_state(wall_cell, State::EMPTY);
                        }
                    } else {
                        if (start_set) {
                            search_grid.set_state(prev_start, State::EMPTY);
                        }
                        start = get_mouse_cell(window);
                        search_grid.set_state(start, State::START);
                        
                        prev_start = start;
                        start_set = true;
                    }
                } else {
                    if (goal_set) {
                        search_grid.set_state(prev_goal, State::EMPTY);
                    }
                    goal = get_mouse_cell(window);
                    search_grid.set_state(goal, State::GOAL);
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
                    reset_bfs(search_grid, start, goal, coords_q, parents);
                }
                
                if (search_status == SEARCH_IN_PROGRESS) {
                    if (start != goal) {
                        search_status = run_bfs(search_grid, start, goal, coords_q, parents);
                    }
                }
            }
        }

        window.clear();
        search_grid.draw();
        window.display();
    }

    return 0;
}

