#include "include/BFS.hpp"
#include <iostream>


std::vector<Coords> get_neighbors(Coords current, const Grid &grid) {
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

    std::cout << "starting bfs" << std::endl;

    std::queue<Coords> coords_q;

    coords_q.push(start);

    Coords root;
    while (!coords_q.empty()) {
        root = coords_q.front();
        coords_q.pop();

        if (root == goal) {
            std::cout << "found goal" << std::endl;
            map[goal.second][goal.first].setFillColor(YELLOW);
            return;
        }

        for (auto neighbor : get_neighbors(root, map)) {
            if (neighbor != start && map[neighbor.second][neighbor.first].getFillColor() != WHITE) {
                coords_q.push(neighbor);
                map[neighbor.second][neighbor.first].setFillColor(WHITE);
            }
        }
    }

    std::cout << "ending bfs" << std::endl;
    return;
}
