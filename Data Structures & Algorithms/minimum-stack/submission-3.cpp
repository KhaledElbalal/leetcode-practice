class MinStack {
public:
    vector<int> stack;
    vector<int> minStack;
    int minimum = INT_MAX;
    MinStack() {
        
    }
    
    void push(int val) {
        this->minimum = min(this->minimum, val);
        stack.push_back(val);
        minStack.push_back(this->minimum);
    }
    
    void pop() {
        stack.pop_back();
        minStack.pop_back();
        if(minStack.empty())
            this->minimum = INT_MAX;
        else
            this->minimum = minStack.back();
    }
    
    int top() {
        return stack.back();
    }
    
    int getMin() {
        return minStack.back();
    }
};
