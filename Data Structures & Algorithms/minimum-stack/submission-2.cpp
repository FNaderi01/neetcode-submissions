class MinStack {
    stack<int> m_main, m_min; 
public:
    MinStack() {
        
    }
    
    void push(int val) {
        m_main.push(val);

        if(m_min.size() == 0) {
            m_min.push(val);
            return;
        }
        m_min.push(min(val, m_min.top())); 
    }
    
    void pop() {
        m_min.pop();
        m_main.pop();
    }
    
    int top() {
        return m_main.top();
    }
    
    int getMin() {
        return m_min.top();
    }
};
