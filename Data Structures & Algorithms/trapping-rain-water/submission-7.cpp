class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;

        int ans = 0;
        int max_left = height[l];
        int max_right = height[r];

        while(l < r) {
            if(max_left < max_right) {
                l++;
                max_left = max(max_left, height[l]);
                ans += (max_left - height[l]);
            } else {
                r--;
                max_right = max(max_right, height[r]);
                ans += (max_right - height[r]);
            }
        }

        return ans;
    }
};
