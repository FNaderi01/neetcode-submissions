class Solution {
public:
    bool isEqual(char a, char b) {
        if(a >= 'A' && a <= 'Z') {
            a = a - 'A' + 'a';
        }
        if(b >= 'A' && b <= 'Z') {
            b = b - 'A' + 'a';
        }

        return (a == b);
    }

    bool isValid(char c) {
        return ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
    }

    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;

        while(left < right) {
            if(!isValid(s[left])) {
                left++;
                continue;
            }
            if(!isValid(s[right])) {
                right--;
                continue;
            }
            if(!isEqual(s[left], s[right])) {
                return false;
            }
            left++;
            right--;
        }

        return true;
    }
};
