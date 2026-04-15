class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string common;
        int i = 0;
        while(true) {
            char currentCharacter;
            if(i >= strs[0].size()) {
                return common;
            } else {
                currentCharacter = strs[0][i];
            }
            for(auto x:strs) {
                if(i >= x.size() || currentCharacter != x[i]) {  
                    return common;
                } 
            }
            common.push_back(currentCharacter);
            i++;
        }
        return common;
    }
};