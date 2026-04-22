class Solution {
public:
    int maxArea(vector<int>& heights) {
        int mx = 0;
        for(int i = 0; i < heights.size(); i++) {
            for(int j = i + 1; j < heights.size(); j++) {
                mx = max(mx, (j - i) * min(heights[j], heights[i]));
            }
        }
        return mx;
    }
};
