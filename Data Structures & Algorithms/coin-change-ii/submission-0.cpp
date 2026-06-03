class Solution {
    vector<vector<int>> dp;
    int ans;
public:
    int calc(int idx, int target, vector<int>& coins) {
        if(target == 0) {
            return 1;
        }

        if(idx >= coins.size()) {
            return 0;
        }

        if(dp[idx][target] != -1) {
            return dp[idx][target];
        }

        int res = 0;
        for(int i = 0; target - i * coins[idx] >= 0; i++) {
            res += calc(idx + 1, target - i * coins[idx], coins);
        }

        dp[idx][target] = res;
        return res;
    }

    int change(int amount, vector<int>& coins) {
        // sort(coins.begin(), coins.end());
        dp.assign(coins.size() + 1, vector<int>(amount + 1, -1));
        ans = 0;
        return calc(0, amount, coins);
        return dp[coins.size() - 1][amount];
    }
};
