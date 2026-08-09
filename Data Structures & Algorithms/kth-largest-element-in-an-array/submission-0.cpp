class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(), nums.end());
        int n = nums.size();
        int count = 0;
        k = k-1;
        while (k--){
            pq.pop();
        }
        return pq.top();
    }
};