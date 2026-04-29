class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<pair<int, int>> v(26, {0, -1}); // {frequency, lastCalled}
        int curCycle = 1;

        for(char ch : tasks) {
            v[ch - 'A'].first++;
        }

        
        while(true) {
            int next = -1;
            int maxx = 0;
            bool cont = false;
    
            for(int i = 0; i < 26; i++) {
                if((v[i].second == -1 || (curCycle - v[i].second - 1 >= n)) && (v[i].first > 0) && (v[i].first > maxx)) {
                    next = i;
                    maxx = v[i].first;
                }

                if(v[i].first > 0) {
                    cont = true;
                }
            }

            if(cont == false) {
                break;
            }
            else if(next != -1) {
                v[next].second = curCycle;
                v[next].first = max(0, v[next].first - 1);
            }
            
            curCycle++;
        }

        return curCycle - 1;
    }
};
