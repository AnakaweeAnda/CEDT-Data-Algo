#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Directions for 4-directional movement
const int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int minBridgeLength(vector<vector<int>> &grid, int R, int C) {
    vector<vector<int>> dist(R, vector<int>(C, -1)); // Distance from A
    queue<pair<int, int>> q;

    // Step 1: Add all cells of country A (1) to the queue
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            if (grid[i][j] == 1) {
                q.push({i, j});
                dist[i][j] = 1; // Start counting the bridge length from A
            }
        }
    }

    // Step 2: BFS to find the shortest bridge
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (const auto &dir : directions) {
            int nx = x + dir[0], ny = y + dir[1];

            // Skip out-of-bound cells or volcanoes
            if (nx < 0 || nx >= R || ny < 0 || ny >= C || grid[nx][ny] == 3 || dist[nx][ny] != -1)
                continue;

            // If we reach a territory of B (2), return the total bridge length
            if (grid[nx][ny] == 2)
                return dist[x][y] + 1;

            // Expand into sea (0)
            if (grid[nx][ny] == 0) {
                q.push({nx, ny});
                dist[nx][ny] = dist[x][y] + 1; // Update distance
            }
        }
    }

    return -1; // Should not happen as a solution is guaranteed
}

int main() {
    // Input reading
    int R, C;
    cin >> R >> C;
    vector<vector<int>> grid(R, vector<int>(C));

    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            cin >> grid[i][j];
        }
    }

    // Solve and output the result
    cout << minBridgeLength(grid, R, C) << endl;

    return 0;
}
