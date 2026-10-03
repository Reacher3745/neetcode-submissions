class Solution {
public:
    string longestPalindrome(string s) {

        // Transform string
        string t = "^";

        for (char c : s) {
            t += "#";
            t += c;
        }

        t += "#$";

        int n = t.size();

        vector<int> P(n, 0);

        int center = 0;
        int right = 0;

        int maxLen = 0;
        int maxCenter = 0;

        for (int i = 1; i < n - 1; i++) {

            // Mirror position
            int mirror = 2 * center - i;

            // Use previously calculated information
            if (i < right)
                P[i] = min(right - i, P[mirror]);

            // Expand around i
            while (t[i + 1 + P[i]] == t[i - 1 - P[i]]) {
                P[i]++;
            }

            // Update center and right boundary
            if (i + P[i] > right) {
                center = i;
                right = i + P[i];
            }

            // Remember largest palindrome
            if (P[i] > maxLen) {
                maxLen = P[i];
                maxCenter = i;
            }
        }

        // Convert back to original string
        int start = (maxCenter - maxLen) / 2;

        return s.substr(start, maxLen);
    }
};