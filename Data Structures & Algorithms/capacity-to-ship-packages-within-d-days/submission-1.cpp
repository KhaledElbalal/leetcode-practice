class Solution {
public:
    bool isShippable(vector<int>& weights, int days, int capacity) {
        int count = 0, acc = 0;
        for(auto x: weights) {
            if(acc == 0 || acc + x > capacity) {
                count++;
                acc = x;
            } else {
                acc += x;
            }
        }
        return count <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = low * weights.size(), ans = (low + high)/2;
        while(low <= high) {
            int mid = (low + high) / 2;
            if(isShippable(weights, days, mid)) {
                high = mid - 1;
                ans = mid;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};