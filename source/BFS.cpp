#include "include/BFS.hpp"


std::vector<Coords> get_neighbors(Coords &node) {
    std::vector<Coords> neighbors;
    unsigned int x = node[X];
    unsigned int y = node[Y];

    if (y > 0)
        neighbors.push_back({x, y - 1});
    if (y < MAP_ROWS - 1) 
        neighbors.push_back({x, y + 1});
    if (x > 0)
        neighbors.push_back({x - 1, y});
    if (x < MAP_COLS - 1)
        neighbors.push_back({x + 1, y});

    return neighbors;
}


SearchStatus run_bfs(Grid &grid, Coords &start, Coords &goal, std::queue<Coords> &coords_q, ParentMap &parents) {

    Coords root;
    for (int i = 0; i < STEPS_PER_FRAME; ++i) {

        if (coords_q.empty()) {
            return SEARCH_COMPLETED;
        }

        root = coords_q.front();
        coords_q.pop();

        if (root == goal) {

            grid.set_state(goal, State::GOAL);

            Coords curr = parents[goal];    // parents[goal] is null if start == goal, which is why in main() we need to check
                                            // if start == goal before running run_bfs()
            while (curr != start) {
                grid.set_state(curr, State::PATH);
                curr = parents[curr];
            }

            return SEARCH_COMPLETED;
        }

        for (auto neighbor : get_neighbors(root)) {

            if (grid.get_state(neighbor) != State::VISITED && !grid.cell_is_wall(neighbor) && neighbor != start) {
                coords_q.push(neighbor);
                grid.set_state(neighbor, State::VISITED);
                parents[neighbor] = root;
            }
        }
    }

    return SEARCH_IN_PROGRESS;
}

void reset_bfs(Grid& grid, Coords& start, Coords& goal, std::queue<Coords>& coords_q, ParentMap& parents) {
    grid.reset();
    grid.set_state(start, State::START);
    grid.set_state(goal, State::GOAL);
    std::queue<Coords> empty_q;
    coords_q.swap(empty_q);
    parents.clear();
    coords_q.push(start);
}
