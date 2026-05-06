class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int l = 0, r = 0;
        string newString = "";
        while(newString.size() < word1.size() + word2.size()) {
            if(l < word1.size()) {
                newString.push_back(word1[l++]);
            }
            if(r < word2.size()) {
                newString.push_back(word2[r++]);
            }
        }
        return newString;
    }
};