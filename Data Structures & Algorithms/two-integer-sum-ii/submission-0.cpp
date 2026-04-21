class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, r = numbers.size() - 1;
        vector<int> ans;
        while(l < r) {
            int currentSum = numbers[l] + numbers[r];
            if(target > currentSum) l++;
            else if(target < currentSum) r--;
            else return {l + 1,r + 1};
        }
    }
};
