class Solution {
    unordered_set<int> s;
public:
    int getSumSquareDigits(int n) {
        int ans = 0;
        while(n > 0) {
            ans += (n % 10) * (n % 10);
            n /= 10;
        }

        return ans;
    }
    bool isHappy(int n) {
        int a = getSumSquareDigits(n);
        if(a == 1) {
            return true;
        }

        if(s.find(a) != s.end()) {
            return false;
        }

        s.insert(a);
        return isHappy(a);
    }
};
