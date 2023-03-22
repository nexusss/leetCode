class MinStack {
    stack <int> st;
        vector <int> minValues;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        st.emplace(val);
        if (minValues.empty() || minValues.back() >= val){
            minValues.emplace_back(val);
        }
    }
    
    void pop() {
        if (!st.empty()){
            if (st.top() == minValues.back()){
                minValues.pop_back();
            }
            st.pop();
        }
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        if (minValues.empty()){
            return numeric_limits<int>::min();
        }
        return minValues.back();
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