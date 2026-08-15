class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans = {{}};
        int n = nums.size();
        
        for(int num : nums){
            int a = ans.size();
            for (int i = 0; i<a; i++){
                vector<int> subset = ans[i];
                subset.push_back(num);
                ans.push_back(subset);
            }
        }

        return ans;

    }
};
