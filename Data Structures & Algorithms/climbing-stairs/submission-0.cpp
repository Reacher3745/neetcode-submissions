class Solution {
public:
    int climbStairs(int n) {
        int prev = 1; 
        int prev2 = 0;
        
        while(n--){
            int curr = prev + prev2;
            prev2 = prev;
            prev = curr;
        }

        return prev;
    }
};
