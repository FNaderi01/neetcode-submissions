class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> min_left(n, -1);
        vector<int> min_right(n, n);

        for(int i = n - 2; i >= 0; i--) {
            // cout<<i<<", ";
            int j = i + 1;
            while(j < n && heights[j] >= heights[i]) {
                j = min_right[j];
            }
            min_right[i] = j;
        }
        cout<<endl;
        for(int i = 1; i < n; i++) {
            int j = i - 1;
            while(j > -1 && heights[j] >= heights[i]) {
                j = min_left[j];
            }
            min_left[i] = j;
        }

        int ans = 0;

        for(int i = 0; i < n; i++) {
            int area = (min_right[i] - min_left[i] - 1) * heights[i];
            // cout<<min_left[i]<<", "<<min_right[i]<<", "<<heights[i]<<", "<<area<<endl;
            
            ans = max(ans, area);
        }
        return ans;
        
    }
};
