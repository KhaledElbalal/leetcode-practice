class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int ans = 1;
        vector<pair<int,int>> pos;
        for(int i = 0; i < position.size(); i++) {
            pos.push_back({position[i], speed[i]});
        }
        sort(pos.begin(), pos.end());
        for(int i = position.size() - 1; i > 0; i--) {
            double firstCarTime = (double)(target - pos[i].first) / (double)pos[i].second; 
            double secondCarTime = (double)(target - pos[i-1].first) / (double)pos[i-1].second; 
            if(secondCarTime - firstCarTime < 0.00000001) {
                pos[i-1] = pos[i];
            } else {
                ans++;
            }
        }
        return ans;
    }
};
