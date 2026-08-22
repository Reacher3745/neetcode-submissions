class Solution {
public:

    void dfs(int i, vector<vector<int>> &ans, vector<int> &nums, vector<int> &subset){
        int n = nums.size();
        if(i == n) {
            ans.push_back(subset);
            return;
        };
        // ans.push_back(subset);

        subset.push_back(nums[i]);
        dfs(i+1, ans, nums, subset);

        subset.pop_back();
        dfs(i+1, ans, nums, subset);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans; 
        vector<int> subset;   
        dfs(0, ans, nums, subset);
        return ans;
    }
};
