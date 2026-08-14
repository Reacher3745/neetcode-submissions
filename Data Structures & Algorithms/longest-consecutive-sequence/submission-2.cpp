class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty())
            return 0;

        priority_queue<int> pq(nums.begin(), nums.end());

        int count = 1;
        int longest = 1;

        int x = pq.top();
        pq.pop();

        while (!pq.empty()) {
            if (pq.top() == x) {
                pq.pop();
                continue;
            }

            if (pq.top() == x - 1) {
                count++;
            } else {
                count = 1;
            }

            longest = max(longest, count);

            x = pq.top();
            pq.pop();
        }

        return longest;
    }
};