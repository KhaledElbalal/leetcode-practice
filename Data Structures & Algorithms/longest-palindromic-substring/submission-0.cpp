class Solution {
public:

    bool isPalindrome(string s) {
        for(int i = 0; i < s.size() / 2; i++) {
            if(s[i] != s[s.size() - i - 1])
                return false;
        }
        return true;
    }
    string longestPalindrome(string s) {
        int n = s.size();
        string longest = s.substr(0,1);
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j <= n - i; j++) {
                string sub = s.substr(j, i);
                if(isPalindrome(sub)) {
                    longest = sub;
                    break;
                }
            }
        }
        return longest;
    }
};
