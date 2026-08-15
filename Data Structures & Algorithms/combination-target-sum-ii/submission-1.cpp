class Solution {
public:
    vector<vector<int>> ans;

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(0, {}, 0, candidates, target);
        return ans;
    }

private:
    void dfs(int i, vector<int> cur, int total, vector<int>& candidates, int target) {

        if (total == target) {
            ans.push_back(cur);
            return;
        }

        for (int j = i; j < candidates.size(); j++) {

            if (j > i && candidates[j] == candidates[j - 1])
                continue;

            if (total + candidates[j] > target)
                break;

            cur.push_back(candidates[j]);

            dfs(j + 1, cur, total + candidates[j], candidates, target);

            cur.pop_back();
        }
    }
};