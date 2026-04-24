class Solution {
public:
    bool evaluateK(vector<int>& piles, int k, int h) {
        int numberOfHours = 0;
        for(auto x:piles) {
            numberOfHours += (x + k - 1) / k;
        }
        return numberOfHours <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = *max_element(piles.begin(), piles.end());
        int mid = -1, ans = h;
        while(low <= high) {
            mid = (high + low) / 2;
            if(evaluateK(piles, mid, h)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
