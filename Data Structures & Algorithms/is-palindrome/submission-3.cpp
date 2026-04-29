class Solution {
public:
    bool isValid(char c) {
        return ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
    }
    char lower(char ch) {
        if(ch >= 'A' && ch <= 'Z')
            return ch - 'A' + 'a';
        return ch;
    }
    bool isPalindrome(string s) {
        string t = "";
        for(char ch: s) {
            if(isValid(ch)) t += lower(ch);        
        }
        string trev = t;
        reverse(trev.begin(), trev.end());
        return t == trev;

    }
};
