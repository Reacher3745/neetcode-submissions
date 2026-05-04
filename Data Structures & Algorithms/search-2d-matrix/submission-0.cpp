class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int low = 0, high = m - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (matrix[mid][0] <= target && matrix[mid][n - 1] >= target) {
                int left = 0, right = n - 1;
                while (left <= right) {
                    int center = (left + right) / 2;
                    if (matrix[mid][center] == target) return true;
                    else if (matrix[mid][center] > target) right = center - 1;
                    else left = center + 1;
                }
                return false;
            }
            else if (matrix[mid][n - 1] < target) low = mid + 1;
            else high = mid - 1;
        }
        return false;
    }
};