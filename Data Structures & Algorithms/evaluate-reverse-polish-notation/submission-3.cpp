class Solution {
public:
    string calculate(string a, string b, string op) {
        int n = stoi(a);
        int m = stoi(b);
        // cout<<n<<", "<<m<<", "<<op<<endl;
        if(op == "+") {
            return to_string(n + m);
        }
        if(op == "-") {
            return to_string(n - m);
        }
        if(op == "*") {
            return to_string(n * m);
        }
        return to_string(n / m);
    }


    int evalRPN(vector<string>& tokens) {
        int ans = 0;
        stack<string> stk;

        for(int i = 0; i < tokens.size(); i++) {
            if(tokens[i] == "+" || tokens[i] == "-" ||
               tokens[i] == "*" || tokens[i] == "/" ) {
                
                string a = stk.top();
                stk.pop();
                string b = stk.top();
                stk.pop();
                stk.push(calculate(b, a, tokens[i]));
            } else {
                stk.push(tokens[i]);
            }
        }

        return stoi(stk.top());
    }
};
