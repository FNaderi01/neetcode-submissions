class Solution {
public:
    int maxArea(vector<int>& heights) {

      int ans = -1;

      for(int i = 0; i < heights.size(); i++) {
        for(int j = i + 1; j < heights.size(); j++) {
            int cap = min(heights[i], heights[j]) * (j - i);
            ans = max(ans, cap);
        }
      }
      
      return ans;
    }
};
