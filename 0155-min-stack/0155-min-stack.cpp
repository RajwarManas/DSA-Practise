class MinStack {
    stack<int> st;
    stack<int> minSt;
public:
    MinStack() {
    }
    void push(int val) {
        if(minSt.empty()) minSt.push(val);
        else minSt.push(min(val,minSt.top()));
        st.push(val);
    }
    void pop() {
        minSt.pop();
        st.pop();   
    }
    int top() {
        return st.top();   
    }
    int getMin() {
        return minSt.top();
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