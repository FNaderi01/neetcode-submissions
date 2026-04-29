class Solution {
public:
    bool isOpen(char a){
        return a=='[' || a== '{' || a =='(';
    }
    char close(char a){
        if (a == '[') return ']';
        if(a== '{') return '}';
        if(a=='(') return ')';
        return 0;
    }
    bool isValid(string s) {
    stack<char> stk;
    int i =0;
    while(i<s.size()){
        if(isOpen(s[i])) stk.push(s[i]);

        else {
            if(stk.empty()) return false;

            if(close(stk.top()) != s[i] ) return false;
            stk.pop();
        }
        i++;

    }
    return stk.empty();
    }
};
