class Solution {
public:
    int mySqrt(int x) {
        long low = 0, high = INT32_MAX;
        long ans = high;
        while(low <= high) {
            long mid = (low + high) / 2;
            if(mid * mid <= (long)x) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return (int)ans;
    }
};