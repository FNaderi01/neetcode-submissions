class Solution {
public:
    bool bsearch(int s, int e, vector<int>& nums, int target) {
        cout<<s<<", "<<e<<endl;
        if(s > e) {
            return false;
        }

        int mid = (e - s) / 2 + s;
        if(nums[mid] == target) {
            return true;
        }
        if(nums[mid] > target) {
            return bsearch(s, mid - 1, nums, target);
        }
        return bsearch(mid + 1, e, nums, target);
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
 
        /* First find the row in which lies the target, using binary search. */
        int s = 0;
        int e = m - 1;
        int mid = 0;
        while(s < e) {
            mid = (e - s) / 2 + s;
            if(matrix[mid][0] <= target && matrix[mid][n-1] >= target) {
                break;
            }
            if(matrix[mid][0] > target) {
                e = mid - 1;
            } else if(matrix[mid][n - 1] < target) {
                s = mid + 1;
            }
        }

        if(e < s){
            return false;
        }
        mid = (e - s) / 2 + s;
        cout<<mid<<endl;
        return bsearch(0, n - 1, matrix[mid], target);
    }
};
