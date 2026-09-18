class Solution {
public:
    string multiply(string num1, string num2) {
        deque<int>v1;
        deque<int>result;
        result.push_back(0);
        for(int i = 0 ; i < num1.size() ; i++) v1.push_front(num1[i] - '0');
        int pow = 0;
        for(int i = num2.size() - 1 ; i >= 0 ; i--) {
            deque<int>x = multi(v1, num2[i] - '0');
            for(int j = 1 ; j <= pow ; j++) x.push_front(0);
            pow++;
            result = bigSum(result, x);
        }
        while(result.size() > 1 && result.back() == 0) result.pop_back();
        string s = "";
        for(int i = result.size() - 1 ; i >= 0 ; i--) {
            s += result[i] + '0';
        }
        return s;

    }

    deque<int> bigSum(deque<int> &a, deque<int> &b) {
        deque<int>sum;
        if(a.size() < b.size()) swap(a, b);
        while(b.size() < a.size()) b.push_back(0);
        int carry = 0;
        for(int i = 0 ; i < a.size() ; i++) {
            int x = (a[i] + b[i] + carry) % 10;
            carry = (a[i]  + b[i] + carry) / 10;
            sum.push_back(x);
        }
        if(carry > 0) sum.push_back(carry);
        return sum;
    }

    deque<int> multi(deque<int> &a, int b) {
        int carry = 0;
        deque<int>res;
        for(int x: a) {
            int y = ((x * b) + carry) % 10;
            carry = ((x * b) + carry) / 10;
            res.push_back(y);
        }
        if(carry > 0) res.push_back(carry);
        return res;
    }

};
