class Solution {
public:
    void dfs(int i, int j, vector<vector<char>> &grid) {

        // Boundary and water check
        if (i < 0 || i >= grid.size() ||
            j < 0 || j >= grid[0].size() ||
            grid[i][j] == '0') {
            return;
        }

        // Mark the current land cell as visited
        grid[i][j] = '0';

        // Visit all 4 directions
        dfs(i + 1, j, grid);
        dfs(i - 1, j, grid);
        dfs(i, j + 1, grid);
        dfs(i, j - 1, grid);
    }

    int numIslands(vector<vector<char>>& grid) {

        if (grid.empty()) return 0;

        int n = grid.size();
        int m = grid[0].size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (grid[i][j] == '1') {
                    dfs(i, j, grid);
                    count++;
                }

            }
        }

        return count;
    }
};