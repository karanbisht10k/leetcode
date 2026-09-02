class MinStack {
public:
    stack<long long> st;
    long long minval;
    MinStack() {
    }
    void push(int val) {
        if (st.empty()){
            minval = val;
            st.push(val);
        }
        else if (val >= minval) {
            st.push(val);
        }
        else {
            st.push(2LL * val -minval);
            minval = val;
        }
    }
    void pop() {
        if (st.empty()) {
            return;
        }
        long long x = st.top();
        st.pop();
        if (x <minval) {
            minval = 2LL *minval - x;
        }
    }
    int top() {
        if (st.top() < minval) {
            return (int)minval;
        }
        return (int)st.top();
    }
    int getMin() {
        return (int)minval;
    }
};
