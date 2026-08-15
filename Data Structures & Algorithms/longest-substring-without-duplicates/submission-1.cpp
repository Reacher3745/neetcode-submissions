class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int longest = 0;
        int l = 0; 
        unordered_set<char> mp;
        for (int i = 0; i<n; i++){
            while(mp.find(s[i]) != mp.end()){
                mp.erase(s[l]);
                l++;
            }
            mp.insert(s[i]);
            longest = max(longest, i - l + 1);
        }

        return longest;

        
    }
};
