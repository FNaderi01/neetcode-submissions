class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        vector<int>greatestRight(height.size(), 0);
        vector<int>greatestLeft(height.size(), 0);
        for(int i = height.size() - 2 ; i >= 0 ; i--) {
            greatestRight[i] = max(height[i+1], greatestRight[i+1]);
        }
        for(int i = 1 ; i < height.size() ; i ++) {
            greatestLeft[i] = max(height[i-1], greatestLeft[i-1]);
        }
        for(int i = 0 ; i < height.size() ; i++) {
            if(height[i] < greatestLeft[i] and height[i] < greatestRight[i]) {
                ans += min(greatestLeft[i], greatestRight[i]) - height[i];
            }
        }
        return ans;
    }
};
