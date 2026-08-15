class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int l1 = s1.size();
        int l2 = s2.size();

        if (l2 < l1) return false;
        unordered_map<char, int> cnt;
        for (char it : s1) cnt[it]++;
        int req = cnt.size();

        for (int i = 0; i<l2; i++) {
            unordered_map<char, int> mp;
            int cur = 0;
            for (int j = i; j<l2; j++){
                char c = s2[j];
                mp[c]++;

                if(cnt[c] < mp[c]) break;
                if(cnt[c] == mp[c]) cur++;
                if(cur == req) return true;
            }

        }
        return false;
    }
};
