class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<pair<int, int>> v(26, {0, -1}); // {frequency, lastCalled}
        int curCycle = 1;

        for(char ch : tasks) {
            v[ch - 'A'].first++;
        }

        bool cont = true;
        while(cont) {
            int next = 0;
            int maxx = 0;
            bool still = false;
            for(int i = 0; i < 26; i++) {
                if((v[i].second == -1 || (curCycle - v[i].second - 1 >= n)) && v[i].first > 0) {
                    if(v[i].first > maxx) {
                        next = i;
                        maxx = v[i].first;
                    }
                }

                if(v[i].first > 0) {
                    still = true;
                }
            }

            if(maxx != 0) {
                v[next].second = curCycle;
                v[next].first = max(0, v[next].first - 1);
                
            } else if (still == false){
                cont = false;
                continue;
            }
            curCycle++;
        }

        return curCycle - 1;
    }
};
