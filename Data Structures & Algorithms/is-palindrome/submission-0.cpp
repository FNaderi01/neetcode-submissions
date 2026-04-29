class Solution {
public:
    char lower(char c){
        if('a' <= c && c <= 'z') return c;
        if('A' <= c && c <= 'Z') return c-'A' + 'a';
        if('0' <= c && c <= '9') return c;
        return ' ';
    }

    bool isPalindrome(string s) {
        int i, j;
        i =0;
        j= s.size() -1;
        while(i<=j){
            char a = lower(s[i]);
            char b = lower(s[j]);
            if(a == ' '){
                i++;
                continue;
            }
            if(b == ' '){
                j--;
                continue;
            }
            if(a != b) {
                return false;
            }
            i++;
            j--;
            
        }
        return true;
    }
};
