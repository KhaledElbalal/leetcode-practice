class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(auto x:tokens) {
            int z = 0, y = 0;
            if (x == "+") {
                z = st.top();
                st.pop();
                y = st.top();
                st.pop();
                st.push(z + y);
            } 
            else if (x == "*") {
                z = st.top();
                st.pop();
                y = st.top();
                st.pop();
                st.push(z * y);
            } else if(x == "/") {
                z = st.top();
                st.pop();
                y = st.top();
                st.pop();
                st.push(y/z);
            }
            else if(x == "-") {
                z = st.top();
                st.pop();
                y = st.top();
                st.pop();
                st.push(y-z);
            }
            else {
                st.push(stoi(x));
            }
        }
        return st.top();
    }
};
