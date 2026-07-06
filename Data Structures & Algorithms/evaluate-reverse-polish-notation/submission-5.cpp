class Solution {
public:
    int calc(int m_a, int m_b, string op) {
        if(op == "+") {
            return m_a + m_b;
        }
        if(op == "-") {
            return m_a - m_b;
        }
        if(op == "*") {
            return m_a * m_b;
        }
        if(op == "/") {
            return m_a / m_b;
        }

        return 1;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;

        for(int i = 0; i < tokens.size(); i++) {
            if(tokens[i] == "+" || tokens[i] == "-" ||
               tokens[i] == "*" || tokens[i] == "/") {

                int a = stk.top();
                stk.pop();
                int b = stk.top();
                stk.pop();

                stk.push(calc(b, a, tokens[i]));

            } else {
                stk.push(stoi(tokens[i]));
            }
        }

        return stk.top();
    }
};
