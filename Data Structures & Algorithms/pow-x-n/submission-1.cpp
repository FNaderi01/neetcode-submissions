class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) {
            return 1;
        }

        double temp = 1;
        if(n < 0) {
            x = 1 / x;
            if(n == INT_MIN) {
                n++;
                temp = x;
            }
            n *= -1;
        }

        double res = x;
        while (n > 1) {
            if(n % 2 == 1) {
                temp *= res;
            }
            res *= res;

            n /= 2;
        }
        
        return res * temp;
    }
};
