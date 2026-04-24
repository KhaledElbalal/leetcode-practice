class Solution {
public:
    int characterReplacement(string s, int k) {
        // okay so my first thought when I see repeated characters is the ability to compress them 
        // into the form char,number_repeated
        // so we can keep each char from that into a vector array that contains a pair
        // pair has number_repeated and terminal_index, then we can fill in k spaces greedly
        // actually better to use a tuple so we can have starting index
        unordered_map<char,vector<tuple<int,int,int>>> mp;
        for(int i = 0; i < s.size(); i++) {
            int r = i;
            int count = 0;
            if(!mp.contains(s[i])) {
                mp[s[i]].push_back({0,-1,-1});
            }
            tuple<int,int,int> number_entry;
            while(r < s.size() && s[r] == s[i]) {
                number_entry = {++count,i,r++};
            }
            mp[s[i]].push_back(number_entry);
            i = r - 1;
        }
        int ans = 1;
        // now for each character we iterate over the array and try to fill gaps with K
        // we actually want also to have an imaginary bound at the end for the algorithm to work
        // and an imaginary first one as well
        for(auto [u,v]:mp) {
            v.push_back({0,s.size(),s.size()});
            for(int i = 0; i < v.size(); i++) {
                // edge case where there is only 1 array
                int cpy = k;
                ans = max(ans, get<0>(v[i]));
                int r = i + 1, currentSize = get<0>(v[i]);
                while(r < v.size()) {
                    int diff = get<1>(v[r]) - get<2>(v[r - 1]) - 1;
                    if(cpy >= diff) {
                        currentSize += get<0>(v[r]) + diff;
                        ans = max(currentSize, ans);
                        cpy -= diff;
                    } else {
                        break;
                    }
                    r++;
                }
                if(cpy) {
                    ans = max(min((int)s.size(), currentSize+cpy), ans);
                }
            }
        }
        return ans;
    }
};
