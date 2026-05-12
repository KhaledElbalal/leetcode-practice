class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        for(auto x:operations) {
            if(x == "+") {
                int x = st.top(); st.pop();
                int y = st.top();
                st.push(x);
                st.push(x + y);
            } else if (x == "D") {
                st.push(st.top() * 2);
            } else if (x == "C") {
                st.pop();
            } else {
                st.push(stoi(x));
            }
        }
        int sum = 0;
        while(!st.empty()) {
            sum += st.top();
            st.pop();
        }
        return sum;
    }
};