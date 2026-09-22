class CountSquares {
    unordered_map<int, multiset<int>> ms;
public:
    CountSquares() {
        
    }
    
    void add(vector<int> point) {
        ms[point[0]].insert(point[1]);
    }
    
    int count(vector<int> point) {
        int ans = 0;

        int a = point[0];
        int b = point[1];

        for(int y : ms[a]) {
            if(y == b) {
                continue;
            }

            int len = abs(b - y);

            int left_x = point[0] - len;
            int right_x = point[0] + len;

            ans += (ms[left_x].count(b)* ms[left_x].count(y));
            ans += (ms[right_x].count(b)* ms[right_x].count(y));
        }

        return ans;
    }
};
