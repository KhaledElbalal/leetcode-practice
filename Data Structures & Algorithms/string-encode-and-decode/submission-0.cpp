class Solution {
public:

    string encode(vector<string>& strs) {
        string message;
        for(auto x:strs) {
            for(auto y:x) 
                message.push_back(y);
            message.append("/r");
        }
        cout << message;
        return message;
    }

    vector<string> decode(string s) {
        vector<string> answer;
        string temp;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '/' && i < s.size() - 1 && s[i+1] == 'r') {
                answer.push_back(temp);
                i++;
                temp = "";
            } else {
                temp.push_back(s[i]);
            }
        }
        return answer;
    }
};
