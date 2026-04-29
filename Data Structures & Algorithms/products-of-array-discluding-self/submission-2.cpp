class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums;
        }

        int n = nums.size();
        vector<int> output(n, 0);
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        left[0] = nums[0];
        right[n - 1] = nums[n-1];

        for (int i = 1; i < n; i++) {
            left[i] = left[i-1] * nums[i];
        }
        for(int i = n - 2; i >= 0; i--) {
            right[i] = right[i+1] * nums[i];
        }

        output[0] = right[1];
        output[n-1] = left[n-2];

        for (int i = 1; i < n - 1; i++) {
            output[i] = left[i-1] * right[i+1];
        }
        return output;
    }
};
