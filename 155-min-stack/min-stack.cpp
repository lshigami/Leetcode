class MinStack {
    vector<int>st;
    vector<int>ms;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if(ms.empty()||ms.back()>=val) ms.push_back(val);
        st.push_back(val);
    }
    
    void pop() {
        if(st.back()==ms.back()) ms.pop_back();
        st.pop_back();
    }
    
    int top() {
        return st.back();
    }
    
    int getMin() {
        return ms.back();
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