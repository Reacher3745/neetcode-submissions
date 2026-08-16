class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int n = grid.size();
        int m = grid[0].size();

        for(int i = 0 ; i<n; i++){
            for (int j = 0; j<m; j++){
                if(grid[i][j] == 0) q.push({i, j});
            }
        }
        vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int i = 0; i<4; i++){
                int row = r + dirs[i][0];
                int col = c + dirs[i][1];
                if(row<0 || row>=n || col<0 || col>=m || grid[row][col] != INT_MAX) continue;

                grid[row][col] = grid[r][c] + 1;
                q.push({row, col});
            }
            

        }

    }
};
