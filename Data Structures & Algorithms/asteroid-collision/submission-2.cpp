class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        for(auto x:asteroids) {
            if(x > 0) {
                ans.push_back(x);
            } else {
                bool destroyed = false;
                while(!ans.empty() && !destroyed) {
                    int back = ans.back();
                    if(back < 0) {
                        break;
                    } else if(back <= abs(x)) {
                        if(back == abs(x)) destroyed = true;
                        ans.pop_back();
                    } else if(back > abs(x)) { destroyed = true; };
                }
                if(!destroyed) ans.push_back(x);
            }
        }
        return ans;
    }
};