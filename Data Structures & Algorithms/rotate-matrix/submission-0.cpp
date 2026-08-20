class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // (x, y) -> (y, m - 1 - x)
        // (y, m - 1 - x) -> (m - 1 - x, m - 1 - y)
        // (m - 1 - x, m - 1 - y) -> (m - 1 - y, x)
        // (m - 1 - y, x) -> (x, y)

        int n = matrix.size();

        for(int i = 0; i < n / 2; i++) {
            for(int j = 0; j < (n / 2 + n % 2); j++) {
                int x = i;
                int y = j;
                int cur_val = 0;
                int next_val = matrix[x][y];

                for(int k = 0; k < 4; k++) {
                    cout<<x<<" "<<y<<endl;
                    cur_val = next_val;
                    int new_x = y;
                    int new_y = n - 1 - x;

                    next_val = matrix[new_x][new_y];
                    matrix[new_x][new_y] = cur_val;
                    x = new_x;
                    y = new_y;
                }
                cout<<"END OF BATCH"<<endl;
            }
        }

    }
};
