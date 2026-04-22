class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // maximize prices[r] - prices[l] | constraint being r > l -- array not sorted
        int profit = 0;
        priority_queue<int> pq;
        for(auto x:prices) {
            pq.push(-x);
            profit = max(profit, x + pq.top());
        }
        return profit;
    }
};
