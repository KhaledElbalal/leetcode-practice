class MinStack {
public:
    vector<int> stack;
    int minimum = INT_MAX;
    MinStack() {
        
    }
    
    void push(int val) {
        this->minimum = min(this->minimum, val);
        stack.push_back(val);
    }
    
    void pop() {
        int lastVal = stack.back();
        stack.pop_back();
        if(lastVal == this->minimum) {
            this->minimum = *min_element(stack.begin(), stack.end());
        }
        if(stack.empty()) {
            this->minimum = INT_MAX;
        }
    }
    
    int top() {
        return stack.back();
    }
    
    int getMin() {
        return this->minimum;
    }
};
