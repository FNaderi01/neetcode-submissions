class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> nextDay(n);
        vector<int> ans(n);
        nextDay[n - 1] = -1;

        for(int i = n - 2; i >= 0; i--) {
            int j = i + 1;
            while(j != -1 && j < n && temperatures[j] <= temperatures[i]) {
                j = nextDay[j];
            }

            nextDay[i] = j;
        }

        for(int i = 0; i < n; i++) {
            if(nextDay[i] == -1) {
                ans[i] = 0;
            } else {
                ans[i] = nextDay[i] - i;
            }
        }

        return ans;

    }
};
