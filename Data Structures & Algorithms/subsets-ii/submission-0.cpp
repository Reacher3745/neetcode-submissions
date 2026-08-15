class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans = {{}};
        set<vector<int>> s;

        s.insert({});  

        for (int num : nums) {
            int sz = ans.size();

            for (int i = 0; i < sz; i++) {
                vector<int> subset = ans[i];
                subset.push_back(num);

                ans.push_back(subset);
                s.insert(subset);
            }
        }

        vector<vector<int>> arr = vector<vector<int>>(s.begin(), s.end());
        arr.push_back({});
        return arr;
    }
};