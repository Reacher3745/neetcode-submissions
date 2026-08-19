class Solution {
public:
    void dfs(int i, int j, vector<vector<char>> &board, vector<vector<int>> &vis){
        int n = board.size();
        int m = board[0].size();

        if (i<0 || i>=n || j<0 || j>=m || board[i][j] == 'X' || vis[i][j]) return;

        vis[i][j] = 1;
        dfs(i+1, j, board, vis);
        dfs(i-1, j, board, vis);
        dfs(i, j-1, board, vis);
        dfs(i, j+1, board, vis);
        
    }
    
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for(int i = 0; i<n; i++){
            dfs(i, 0, board, vis);
            dfs(i, m-1, board, vis);
        }
        for(int i = 0; i<m; i++){
            dfs(0, i, board, vis);
            dfs(n-1, i, board, vis);
        }

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(!vis[i][j]) board[i][j] = 'X';
            }
        }

        return;


    }
};
