class MinStack {
public:
    stack<int> s1 , s2;
    MinStack() {
        
    }
    
    void push(int x) {
       if(s2.empty() || x <= s2.top()){
           s2.push(x);
       }

       s1.push(x);

    }
    
    void pop() {
        if(s1.top() == s2.top()){
            s2.pop();
        }

        s1.pop();
    }
    
    int top() {
        int x = s1.top();
        return x;
    }
    
    int getMin() {
       int x = s2.top();
       return x;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */