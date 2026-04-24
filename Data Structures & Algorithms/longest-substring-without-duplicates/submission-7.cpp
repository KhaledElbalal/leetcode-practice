class Solution {
public:
    
    int lengthOfLongestSubstring(string s) {
        if(s.empty()) return 0;
        int ans = 1;
        for(int i = 0; i < s.size(); i++) {
            unordered_map<char,int> isExist;
            isExist[s[i]] = i; 
            bool terminated = false;
            for(int r = i + 1; r < s.size(); r++) {
                if(isExist.contains(s[r])) {
                    i = isExist[s[r]];
                    ans = max(ans, r - i);
                    terminated = true;
                    break;
                } else {
                    isExist[s[r]] = r;
                    ans = max(ans, r - i + 1);
                }
            }
            if(!terminated) break;
        }
        return ans;
    }
};
