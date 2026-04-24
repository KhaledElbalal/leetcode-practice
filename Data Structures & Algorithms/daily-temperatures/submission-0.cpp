class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(temperatures.size(), 0);
        for(int i = 0; i < temperatures.size(); i++) {
            int validTemperatureInterval = 0;
            for(int j = i + 1; j < temperatures.size(); j++) {
                if(temperatures[j] > temperatures[i]) {
                    validTemperatureInterval = j - i;
                    break;
                } 
            }
            ans[i] = validTemperatureInterval;

        }
        return ans;
    }
};
