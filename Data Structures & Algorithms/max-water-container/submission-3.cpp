class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int l = 0;
        int r = n - 1;

        int ans = 0;
        while(l < r) {
            // cout<<heights[l]<<" "<<heights[r]<<endl;
            int cap = min(heights[l], heights[r]) * (r - l);
            ans = max(ans, cap);

            if(heights[l] <= heights[r]) {
                l++;
            } else {
                r--;
            }
        }

        return ans;
    }
};
