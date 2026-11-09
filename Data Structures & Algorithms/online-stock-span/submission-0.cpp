class StockSpanner {
public:
    vector<int> dp;
    vector<int> items;
    StockSpanner() {

    }
    
    int next(int price) {
        dp.push_back(1);
        items.push_back(price);
        int i = items.size() - 2;
        while(i >= 0) {
            if(items[i] > price) {break;}
            dp.back() += dp[i];
            i -= dp[i];
        }
        return dp.back();
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */