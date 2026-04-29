class MinStack {
public:
    stack<int> main, myMin;
    MinStack() {
       
    }
    
    void push(int val) {
        main.push(val);
        if (myMin.size() == 0) {
            myMin.push(val);
            return;
        }
        myMin.push(min(myMin.top(), val));
    }
    
    void pop() {
        main.pop();
        myMin.pop();
    }
    
    int top() {
        return main.top();
    }
    
    int getMin() {
        return myMin.top();
    }
};
