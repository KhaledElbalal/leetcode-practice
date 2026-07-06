class KthLargest {
public:
    multiset<int> st;
    int value = 0;
    KthLargest(int k, vector<int>& nums) {
        this->value = k;
        st = multiset<int>(nums.begin(), nums.end());
    }
    
    int add(int val) {
        st.insert(val);
        auto it = next(this->st.rbegin(), this->value - 1);
        return *it;
    }
};
