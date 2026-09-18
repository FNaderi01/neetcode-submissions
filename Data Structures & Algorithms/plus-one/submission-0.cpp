class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        int idx = digits.size() - 1;
        do {
            int s = digits[idx] + carry;
            if(s < 10) {
                digits[idx] = s;
                return digits;
            }

            digits[idx] = 0;
            idx--;
            carry = 1;
        } while(idx >= 0);

        digits.push_back(1);
        reverse(digits.begin(), digits.end());
        return digits;
    }
};
