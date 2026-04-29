class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> sol(temperatures.size(), -1);

        for(int i = temperatures.size() - 2; i >= 0; i--) {
            int j = i + 1;

            while((j != -1) && (temperatures[j] <= temperatures[i])) {
                j = sol[j];
            }
            sol[i] = j;
        }
        
        for(int i = 0; i < temperatures.size(); i++) {
            sol[i] = max(0, sol[i] - i);
        }
        return sol;
    }
};
