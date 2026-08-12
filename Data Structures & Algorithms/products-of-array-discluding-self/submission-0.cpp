class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zeros = 0;
        int n = nums.size();
        int prod = 1;
        int zeroth;

        for (int i = 0; i<n; i++){
            if (nums[i] == 0) zeros++;
        }

        vector<int> arr(n, 0);
        vector<int> ans;
        if (zeros > 1)  return arr;

        else if (zeros == 0) {
            for (int i = 0; i<n; i++) {
                prod = prod*nums[i];
            }

            for(int i = 0; i<n; i++){
                ans.push_back(prod/nums[i]);
            }
            return ans;
        }

        else{
            for (int i = 0; i<n; i++) {
                if(nums[i] == 0) {
                    zeroth = i;
                    continue;
                }
                prod = prod*nums[i];
            }
            arr[zeroth] = prod;
            return arr;

        }
    }
};
