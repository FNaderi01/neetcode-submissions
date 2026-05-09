class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mx = INT_MIN;
        for(int i = 0 ; i < nums.size() ; i++) {
            int cur = 1;
            for(int j = i ; j < nums.size() ; j++) {
                cur *= nums[j];
                mx = max(mx, cur);
            }
        }
        return mx;
    }
};
