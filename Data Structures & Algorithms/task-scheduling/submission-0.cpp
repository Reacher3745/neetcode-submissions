class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        vector<int> freq(26, 0);

        // Count frequency
        for (char c : tasks) {
            freq[c - 'A']++;
        }

        // Find maximum frequency
        int maxFreq = 0;

        for (int x : freq) {
            maxFreq = max(maxFreq, x);
        }

        // Count how many tasks have maximum frequency
        int countMax = 0;

        for (int x : freq) {
            if (x == maxFreq) {
                countMax++;
            }
        }

        int ans = (maxFreq - 1) * (n + 1) + countMax;

        return max((int)tasks.size(), ans);
    }
};