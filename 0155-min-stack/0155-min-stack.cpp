class MinStack {
    private:
    stack<int>minStack;
    stack<int> mainStack;
public:
    MinStack() {
        
    }
    
    void push(int value) {
        mainStack.push(value);
        if(minStack.empty()){
            minStack.push(value);
        }
        else{
            minStack.push(min(value,minStack.top()));
        }
        
    }
    
    void pop() {
        minStack.pop();
        mainStack.pop();
        
    }
    
    int top() {
        return mainStack.top();
        
    }
    
    int getMin() {
        return minStack.top();
        
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */