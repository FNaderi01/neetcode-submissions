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
        while(isOpen(s[i]) ){
            stk.push(s[i]);
            i++;
        }
        if(stk.empty()) return false;
        while(!stk.empty() && i<s.size()){
            char x = stk.top();
            // cout<<x<<endl;
            if(s[i]!=close(x)) return false;
            stk.pop();
            i++;
        }
        if(!stk.empty()) return false;

    }
    return true;
    }
};
