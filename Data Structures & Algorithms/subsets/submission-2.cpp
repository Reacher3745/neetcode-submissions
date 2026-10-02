class Solution {
public:
    vector<vector<int>> ans;
    vector<int> subset = {};

    void make_sub(vector<int> &nums, int i){
        if(i == nums.size()){
            ans.push_back(subset);
            return;
        }
        subset.push_back(nums[i]);
        make_sub(nums, i+1);
        subset.pop_back();
        make_sub(nums, i+1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        make_sub(nums, 0);
        return ans;
    }
};
