class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if (nums.empty()) return 0;
        int ans = 1; int counter = 1;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] == nums[i-1] + 1) {
                counter++;
            } else if(nums[i] == nums[i-1]) {
                continue;
            } 
            else {
                counter = 1;
            };
            ans = max(ans, counter);
        }
        return ans;

    }
};
