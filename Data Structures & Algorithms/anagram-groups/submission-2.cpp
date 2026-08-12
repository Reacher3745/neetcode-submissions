class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<string>> mp;

        for (string s : strs) {

            vector<int> freq(26, 0);

            // Count characters
            for (char c : s) {
                freq[c - 'a']++;
            }

            // Build key
            string key;

            for (int x : freq) {
                key += to_string(x);
                key += '#';
            }

            mp[key].push_back(s);
        }

        vector<vector<string>> ans;

        for (auto &it : mp) {
            ans.push_back(it.second);
        }

        return ans;
    }
};