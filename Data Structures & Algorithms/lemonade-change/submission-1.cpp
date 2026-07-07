class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0, twenty = 0;
        for(int i = 0; i < bills.size(); i++) {
            if(bills[i] == 5) {
                five++;
            } else if(bills[i] == 10) {
                if(five > 0) {
                    five--;
                    ten++;
                } else {
                    return false;
                }
            } else {
                if((ten > 0 && five > 0) || five > 2) {
                    twenty++;
                    if(ten) {
                        ten--;
                        five--;
                    } else {
                        five -= 3;
                    }
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};