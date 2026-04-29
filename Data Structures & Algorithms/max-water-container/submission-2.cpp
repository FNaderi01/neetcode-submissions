class Solution {
public:
    int maxArea(vector<int>& heights) {
        int ans = -1;
        int left = 0;
        int right = heights.size() - 1;

        while(left < right) {
            int curCap = min(heights[left], heights[right]) * (right - left);
            ans = max(curCap, ans);

            if(heights[left] <= heights[right]) {
                left++;
            } else {
                right--;
            }
        }

        return ans;
    }
};
