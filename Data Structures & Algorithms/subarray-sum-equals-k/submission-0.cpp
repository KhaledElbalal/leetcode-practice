class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0;
        for(int i = 1; i <= nums.size(); i++) {
            int included = 0;
            int currSum = 0;
            for(int j = 0; j < nums.size(); j++) {
                if(included == i) {
                    currSum -= nums[j - included];
                    included--;
                }
                currSum += nums[j];
                included++;
                if(currSum == k && included == i) {
                    ans++;
                }
            }
        }
        return ans;
    }
};