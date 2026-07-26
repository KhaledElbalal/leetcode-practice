class Solution {
public:
    vector<int> dp = vector<int> (50,0);
    int climbStairs(int n) {
        if(n == 1) {
            return 1;
        }
        if(n == 2) {
            return 2;
        }
        if(!this->dp[n]) {
            this->dp[n] = climbStairs(n - 1) + climbStairs(n - 2); 
        }
        return this->dp[n];
    }
};
