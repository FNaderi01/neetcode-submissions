class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int candid = 0;
        int curGas = 0;
        int curIdx = 0;
        bool done = false;
        while(candid <= n-1) {
            if(curGas + gas[curIdx] - cost[curIdx] >= 0) {
                curGas = curGas + gas[curIdx] - cost[curIdx];
                if(curIdx + 1 >= n) {
                    done = true;
                }
                curIdx = (curIdx + 1)%n;
                if(curIdx == candid) return candid;
            } else {
                if(done) break;
                candid = curIdx + 1;
                curGas = 0;
                curIdx++;
            }
        }
        return -1;
    }
};
