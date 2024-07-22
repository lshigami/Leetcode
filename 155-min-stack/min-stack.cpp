class MinStack {
    vector<int> st; // Stack chính để lưu các giá trị
    vector<int> ms; // Stack lưu giá trị tối thiểu tại mỗi bước

public:
    MinStack() {
    
    }

    void push(int val) {
        st.push_back(val);
        if (ms.empty() || val <= ms.back()) {
            ms.push_back(val);
        } else {
            ms.push_back(ms.back());
        }
    }

    void pop() {
        st.pop_back();
        ms.pop_back();
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
