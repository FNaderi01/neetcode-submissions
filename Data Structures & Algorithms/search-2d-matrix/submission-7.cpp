class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        /* Find the row first. */
        int s = 0; 
        int e = n - 1;

        int r = -1;
        while(s <= e) {
            int mid = (s + e) / 2;

            if(matrix[mid][0] <= target && matrix[mid][m - 1] >= target) {
                r = mid;
                break;
            }

            if(target < matrix[mid][0]) {
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        // cout<<r<<endl;
        if(r == -1) {
            return false;
        }

        s = 0;
        e = m - 1;
        while(s <= e) {
            int mid = (s + e) / 2;

            if(matrix[r][mid] == target) {
                return true;
            }

            if(target < matrix[r][mid]) {
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }

        return false;
    }
};
