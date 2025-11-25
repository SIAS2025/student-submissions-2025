class MinStack {
public:
    MinStack() {

    }
    
    void push(int val) {
        vals.push(val);
        if(min.empty() || val <= min.top())
            min.push(val);
        else
            min.push(min.top());
    }
    
    void pop() {
        if(vals.empty()) 
            return;
        vals.pop();
        min.pop();
    }
    
    int top() {
        return vals.top();
    }
    
    int getMin() {
        return min.top();
    }
    stack<int> vals;
    stack<int> min;
};