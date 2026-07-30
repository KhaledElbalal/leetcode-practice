class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        cost.push_back(0);
        vector<int> answer(cost.size());
        for(int i = 2; i < cost.size(); i++) {
            answer[i] = min(cost[i-1] + answer[i-1], cost[i-2] + answer[i-2]);
        }
        return answer[cost.size()-1];
    }
};
