class MyStack {
public:
    queue<int> first;
    queue<int> second;
    MyStack() {
        
    }
    
    void push(int x) {
        first.push(x);
    }
    
    int pop() {
        int val = this->top();
        first.pop();
        return val;
    }
    
    int top() {
        if(first.size() == 0) {while(!second.empty()) {first.push(second.front());second.pop();}}
        while(first.size() != 1) {
            second.push(first.front());
            first.pop();
        }
        int val = first.front();
        return val;
    }
    
    bool empty() {
        return second.empty() && first.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */