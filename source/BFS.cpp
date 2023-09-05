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


void run_bfs(Grid& map, Coords& start, Coords& goal) {

    std::queue<Coords> coords_q;
    ParentMap parents;

    coords_q.push(start);

    Coords root;
    while (!coords_q.empty()) {
        root = coords_q.front();
        coords_q.pop();

        if (root == goal) {
            map[goal.second][goal.first].setFillColor(YELLOW);

            Coords curr = parents[goal];    // parents[goal] is null if start == goal, which is why we need to check if start == goal before running this function
            while (curr != start) {
                map[curr.second][curr.first].setFillColor(BLUE);
                curr = parents[curr];
            }

            return;
        }

        for (auto neighbor : get_neighbors(root)) {
            if (map[neighbor.second][neighbor.first].getFillColor() != WHITE && !cell_is_wall(map, neighbor) && neighbor != start) {    // Relying on checking node color is not elegant...
                coords_q.push(neighbor);
                map[neighbor.second][neighbor.first].setFillColor(WHITE);   // Must mark visited when enqueueing to optimize. Because of bouncing bfs runs multiple times...
                parents[neighbor] = root;
            }
        }
    }

    return;
}
