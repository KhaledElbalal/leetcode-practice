class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        int curr = digits.size() - 1;
        while(carry && curr != -1) {
            if(digits[curr] == 9) {
                digits[curr] = 0;
                curr--;
            } else {
                digits[curr]++;
                carry = 0;
            }
        }
        if(carry) {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};
