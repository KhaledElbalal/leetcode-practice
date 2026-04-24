class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // maximize sum of total expressions in range arr[n] - arr[n-x]
        // must be in linear time 
        // if we have for example the array 3 4 5, then when deciding when to sell at 5 we can always do steps
        // meaning we can sell at 4 and then buy at 4 and assuming it is increasing it is going to be optimal
        // so in theory as long as price is increasing we can sell it
        // issue is what if price increased then decreased then increased again
        // so we sell at the increased price and buy again when it decreases, we can keep track
        // of minimum price it reached and always sell when price decreased
        int mi = prices[0];
        int profit = 0;
        for(auto x:prices) {
            if(x > mi) {
                profit += x - mi;
            }
            mi = x;
        }
        return profit;
    }
};