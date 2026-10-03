class Solution {
public:
    string longestPalindrome(string s) {

        int n = s.size();

        string sub;
        int sub_len = 0;

        for (int i = 0; i < n - 1; i++) {

            int l = i;
            int r = i + 1;
            int len = 0;

            while (l >= 0 && r < n && s[l] == s[r]) {
                len += 2;
                l--;
                r++;
            }

            if (len > sub_len) {
                sub_len = len;
                sub = s.substr(l + 1, r - l - 1);
            }
        }

        for (int i = 0; i < n; i++) {

            int l = i - 1;
            int r = i + 1;
            int len = 1;

            while (l >= 0 && r < n && s[l] == s[r]) {
                len += 2;
                l--;
                r++;
            }

            if (len > sub_len) {
                sub_len = len;
                sub = s.substr(l + 1, r - l - 1);
            }
        }

        return sub;
    }
};