class Solution {
public:
    void dfs(int i, int j, vector<vector<int>> &grid, int &area){
        if (i<0 || i >= grid.size() || j<0 || j >= grid[0].size() || grid[i][j] == 0) return;

        grid[i][j] = 0;
        area++;

        dfs(i+1, j, grid, area);
        dfs(i-1, j, grid, area);
        dfs(i, j-1, grid, area);
        dfs(i, j+1, grid, area);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int maxi = 0;

        for (int i = 0; i<n; i++){
            for (int j = 0; j<m; j++){
                if(grid[i][j] == 1){
                    int area = 0;
                    dfs(i, j, grid, area);
                    if (area > maxi) maxi = area;

                }
            }
        }

        return maxi;

    }

};
