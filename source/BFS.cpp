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

    std::queue<Coords> coords_q;
    ParentMap parents;

    coords_q.push(start);

    Coords root;
    while (!coords_q.empty()) {
        root = coords_q.front();
        coords_q.pop();

        if (root == goal) {
            map[goal.second][goal.first].setFillColor(YELLOW);
            Coords curr = parents[goal];
            while (curr != start) {
                map[curr.second][curr.first].setFillColor(BLUE);  // e.g., BLUE for the path
                curr = parents[curr];
            }
            return;
        }

        for (auto neighbor : get_neighbors(root, map)) {
            if (neighbor != start && map[neighbor.second][neighbor.first].getFillColor() != WHITE) {
                coords_q.push(neighbor);
                map[neighbor.second][neighbor.first].setFillColor(WHITE);
                parents[neighbor] = root;
            }
        }
    }

    return;
}
