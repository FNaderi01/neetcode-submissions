class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) {
            return 1;
        }

        int temp = 1;
        if(n < 0) {
            x = 1 / x;
            if(n == INT_MIN) {
                n++;
                temp = x;
            }
            n *= -1;
        }

        double t = 1;
        if(n % 2 == 1) {
            t = x;
        }
        double res = myPow(x, n / 2);
        return res * res * t * temp;
    }
};
