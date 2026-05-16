class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int solution = 0;
        for(int i = 1; i <= 32; i++) {
            if((n >> (i-1)) & 1) {
                cout << i << ' ';
                solution += pow(2, 32-i);
            }
        }
        return solution;
    }
};
