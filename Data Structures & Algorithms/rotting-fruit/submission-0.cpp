class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ones = 0;
        int t = 0;
        queue<pair<pair<int, int>, int>> q;

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 2) q.push({{i, j}, t});
            }
        }

        vector<vector<int>> dir= {{1,0}, {0, 1}, {-1, 0}, {0, -1}};

        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int time = q.front().second;
            q.pop();
            t = max(t, time);

            for(int i = 0; i<4; i++){
                int r = row + dir[i][0];
                int c = col + dir[i][1];

                if (r<0 || r>=n || c<0 || c>=m || grid[r][c] != 1) continue;

                grid[r][c] = 2;
                q.push({{r, c}, time + 1});
            }
        }

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 1) return -1;
            }
        }

        return t;
    }
};
