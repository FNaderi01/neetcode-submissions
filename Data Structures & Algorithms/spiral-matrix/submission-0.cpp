class Solution {
public:
    enum DIR {
        L,
        R,
        U,
        D
    };
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        int left = -1;
        int right = m;
        int up = -1; 
        int down = n;

        DIR dir = R;
        vector<int> ans;
        int i = 0; 
        int j = 0;
        while(ans.size() != (m * n)) {
            
            if(j == right) {
                dir = D;
                up++;
                i = up + 1;
                j = j - 1;
                continue;
            }
            if(j == left) {
                dir = U;
                down--;
                i = down - 1;
                j = j + 1;
                continue;
            }

            if(i == down) {
                dir = L;
                right--;
                
                j = right - 1;
                i = i - 1;
                continue;
            }

            if(i == up) {
                dir = R;
                left++;

                j = left + 1;
                i = i + 1;
                continue;
            }
            // cout<<left<<" "<<right<<" "<<up<<" "<<down<<endl;
            // cout<<i<<" "<<j<<endl;
            ans.push_back(matrix[i][j]);

            if(dir == R) {
                j++;
            } else if (dir == D) {
                i++;
            } else if(dir == L) {
                j--;
            } else if(dir == U) {
                i--;
            }
            
        }

        return ans;
    }
};
