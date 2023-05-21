class Solution {
public:
    const int dx[4] = {-1, 1, 0, 0};
    const int dy[4] = {0, 0, -1, 1};

    bool isValid(int i, int j, int n) {
        return (i >= 0 && i < n && j >= 0 && j < n);
    }

    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();

        // Step 1: Find the first island using DFS and mark its cells as -1
        bool found = false;
        for (int i = 0; i < n; ++i) {
            if (found)
                break;
            for (int j = 0; j < n; ++j) {
                if (grid[i][j]) {
                    dfs(i, j, n, grid);
                    found = true;
                    break;
                }
            }
        }

        // Step 2: Perform a BFS search to find the second island
        queue<pair<int, int>> q;
        int steps = 0;

        // Add the cells of the first island to the BFS queue
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == -1) {
                    q.push({i, j});
                }
            }
        }

        // Perform BFS search
        while (!q.empty()) {
            int size = q.size();

            while (size--) {
                auto node = q.front();
                q.pop();

                for (int x = 0; x < 4; ++x) {
                    int ni = node.first + dx[x];
                    int nj = node.second + dy[x];

                    if (isValid(ni, nj, n)) {
                        if (grid[ni][nj] == 1) {
                            return steps;
                        }

                        if (grid[ni][nj] == 0) {
                            grid[ni][nj] = -1;
                            q.push({ni, nj});
                        }
                    }
                }
            }

            steps++;
        }

        return -1; // No path found
    }

    void dfs(int i, int j, int n, vector<vector<int>>& grid) {
        if (i < 0 || i >= n || j < 0 || j >= n || grid[i][j] != 1)
            return;

        grid[i][j] = -1;

        dfs(i - 1, j, n, grid);
        dfs(i + 1, j, n, grid);
        dfs(i, j - 1, n, grid);
        dfs(i, j + 1, n, grid);
    }
};