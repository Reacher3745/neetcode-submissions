class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        for(int i = 0; i<n; i++){
            for(int j = i ; j<m; j++){
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }

        for(int i = 0; i<m/2; i++){
            for(int j = 0; j<n; j++){
                int tem = matrix[j][i];
                matrix[j][i] = matrix[j][m-i-1];
                matrix[j][m-i-1] = tem;
            }
        }
    }
};
