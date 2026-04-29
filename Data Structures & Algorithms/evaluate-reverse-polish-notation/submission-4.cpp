class Solution {
public:
    int calculate(int n, int m, string op) {
        if(op == "+") {
            return (n + m);
        }
        if(op == "-") {
            return (n - m);
        }
        if(op == "*") {
            return (n * m);
        }
        return (n / m);
    }


    int evalRPN(vector<string>& tokens) {
        int ans = 0;
        stack<int> stk;

        for(int i = 0; i < tokens.size(); i++) {
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/" ) {
                int a = stk.top();
                stk.pop();
                int b = stk.top();
                stk.pop();
                stk.push(calculate(b, a, tokens[i]));
            } else {
                stk.push(stoi(tokens[i]));
            }
        }

        return (stk.top());
    }
};
