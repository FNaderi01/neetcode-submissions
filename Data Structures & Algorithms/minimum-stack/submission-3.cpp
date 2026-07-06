class MinStack {
    stack<int> main, minS;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        main.push(val);

        if(minS.empty()) {
            minS.push(val);
            return;
        }

        int top = minS.top();
        if(val < top) {
            minS.push(val);
        } else {
            minS.push(top);
        }
    }
    
    void pop() {
        main.pop();
        minS.pop();
    }
    
    int top() {
        return main.top();
    }
    
    int getMin() {
        return minS.top();
    }
};
