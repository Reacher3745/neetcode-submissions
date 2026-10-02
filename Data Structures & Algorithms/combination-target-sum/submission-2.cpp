class Solution {
public:
    vector<vector<int>> ans;
    vector<int> subset;

    void make(vector<int> &nums, int target, int total, int i){
        if(i == nums.size()) return;
        if(total == target){
            ans.push_back(subset);
            return;
        }
        if(total > target) return ;

        subset.push_back(nums[i]);
        make(nums, target, total + nums[i], i);
        subset.pop_back();
        make(nums, target, total , i+1);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        make(nums, target, 0, 0);
        return ans;
    }
};
