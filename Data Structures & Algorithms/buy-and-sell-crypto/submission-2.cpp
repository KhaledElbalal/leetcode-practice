class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // maximize prices[r] - prices[l] | constraint being r > l -- array not sorted
        int profit = 0, currentMin = INT_MAX;
        for(auto x:prices) {
            profit = max(x - currentMin, profit);
            currentMin = min(currentMin, x);
        }
        return profit;
    }
};
