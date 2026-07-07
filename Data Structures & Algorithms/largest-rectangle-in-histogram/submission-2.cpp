class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        vector<int> left(n, -1);
        vector<int> right(n, n);

        for(int i = n - 2; i >= 0; i--) {
            int j = i + 1;
            while(j < n && heights[j] >= heights[i]) {
                j = right[j];
            }

            right[i] = j;
        }

        for(int i = 1; i < n; i++) {
            int j = i - 1;

            while(j > -1 && heights[j] >= heights[i]) {
                j = left[j];
            }
            
            left[i] = j;
        }

        int ans = 0;

        for(int i = 0; i < n; i++) {
            int area = (right[i] - left[i] - 1) * heights[i];

            ans = max(ans, area);
        }

        return ans;
        
    }
};
