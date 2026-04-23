class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        sort(s1.begin(), s1.end());
        for(int i = 0; i < s2.size(); i++) {
            string newString;
            for(int j = i; (j - i) < s1.size() && j < s2.size(); j++) {
                newString.push_back(s2[j]);
            }
            sort(newString.begin(), newString.end());
            if(s1 == newString) {
                return true;
            }
        }
        return false;
    }
};
