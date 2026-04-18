class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red = 0, white = 0, blue = 0;
        for(auto x:nums) {
            if(x == 0) {
                red++;
            } else if(x == 1) {
                white++;
            } else {
                blue++;
            }
        }
        for(auto &x:nums) {
            if(red) {
                red--;
                x = 0;
            } else if(white) {
                white--;
                x = 1;
            } else {
                x = 2;
            }
        }
    }
};