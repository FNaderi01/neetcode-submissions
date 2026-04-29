class Solution {
public:
    int getSum(int a, int b) {
        if((a & b) == 0) return a^b;
        int x = (a&b)<<1;

        return getSum((a^b), x);
    }
};
