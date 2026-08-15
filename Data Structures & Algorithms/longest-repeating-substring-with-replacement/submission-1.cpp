class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> mp;
        int n = s.size();
        int count = 0;
        int l = 0;
        int ans = 0;

        for(int i = 0; i<n; i++) {
            mp[s[i]]++;
            count = max(count, mp[s[i]]);

            while ((i - l + 1) - count > k) {
                mp[s[l]]--;
                l++;
            }

            ans = max(ans, i - l + 1);
        }

        return ans;

        
    }
};
