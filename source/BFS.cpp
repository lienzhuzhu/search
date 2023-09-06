#include "include/BFS.hpp"
#include <iostream>


std::vector<Coords> get_neighbors(Coords current) {
    std::vector<Coords> neighbors;
    int x = current.first;
    int y = current.second;

    // Check above
    if (y > 0) {
        neighbors.push_back(Coords(x, y - 1));
    }
    // Check below
    if (y < MAP_ROWS - 1) {
        neighbors.push_back(Coords(x, y + 1));
    }
    // Check left
    if (x > 0) {
        neighbors.push_back(Coords(x - 1, y));
    }
    // Check right
    if (x < MAP_COLS - 1) {
        neighbors.push_back(Coords(x + 1, y));
    }

    return neighbors;
}


SearchStatus run_bfs(Grid& map, Coords& start, Coords& goal, std::queue<Coords>& coords_q, ParentMap& parents) {


    Coords root;
    for (int i = 0; i < STEPS_PER_FRAME; ++i) {
        //std::cout << i << std::endl;

        if (coords_q.empty()) {
            return SEARCH_COMPLETED;
        }

        root = coords_q.front();
        coords_q.pop();
        std::cout << root.second << " " << root.first << std::endl;

        if (root == goal) {
            std::cout << "search completed" << std::endl;

            map[goal.second][goal.first].setFillColor(YELLOW);

            Coords curr = parents[goal];    // parents[goal] is null if start == goal, which is why in main() we need to check
                                            // if start == goal before running run_bfs()
            while (curr != start) {
                map[curr.second][curr.first].setFillColor(BLUE);
                curr = parents[curr];
            }

            return SEARCH_COMPLETED;
        }

        for (auto neighbor : get_neighbors(root)) {
            //std::cout << neighbor.second << " " << neighbor.first << std::endl;

            // REFACTOR: Relying on checking node color is not elegant...
            if (map[neighbor.second][neighbor.first].getFillColor() != WHITE && !cell_is_wall(map, neighbor) && neighbor != start) {
                coords_q.push(neighbor);

                // NOTE: Must mark visited when enqueueing to optimize. Because of bouncing bfs runs multiple times...
                map[neighbor.second][neighbor.first].setFillColor(WHITE);   
                parents[neighbor] = root;
            }
        }
    }

    return SEARCH_IN_PROGRESS;
}
