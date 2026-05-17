class Solution {
public:
    bool canJump(vector<int>& nums) {
        int iterator = 0;
        while(iterator < nums.size() - 1) {
            cout << iterator << ' ';
            if(nums[iterator] == 0) {
                break;
            } 
            else {
                int candidate = iterator + nums[iterator];
                int score = nums[iterator];
                for(int i = iterator + 1; i <= iterator + nums[iterator]; i++) {
                    if(nums[i] == 0) continue;
                    int new_score = (i - iterator) + nums[i];
                    if(new_score >= score) {
                        candidate = i;
                        score = new_score;
                    } 
                }
                iterator = candidate;
            }
        }
        return iterator + 1 >= nums.size();
    }
};
