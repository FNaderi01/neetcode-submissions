class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int curMin = INT_MAX;

        for(int i = 0; i < prices.size(); i++) {
            curMin = min(curMin, prices[i]);
            ans = max(ans, (prices[i] - curMin));
        }

        return ans;
    }
};
