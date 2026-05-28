class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
       int n = gas.size();
       int totalGas = 0;
       int totalCost = 0;
       for(int i = 0 ; i < n ; i++) {
        totalGas += gas[i];
        totalCost += cost[i];
       }
       if(totalCost > totalGas) return -1;
       int total = 0;
       int ans = 0;
       for(int i = 0 ; i < n ; i++) {
        if(total + gas[i] - cost[i] < 0) {
            ans = i+1;
            total = 0;
        } else {
            total = total + gas[i]  - cost[i];
        }
       }
       return ans;
    }
};
