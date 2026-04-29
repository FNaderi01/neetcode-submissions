class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r_start, r_end, r_mid=0;
        int n = matrix[0].size();
        r_start = 0;
        r_end = matrix.size() -1;

        while (r_start <= r_end){
            r_mid = (r_end - r_start)/2 + r_start;
            cout<<r_mid<<endl;
            if(matrix[r_mid][0] <= target && matrix[r_mid][n-1]>= target )
                break;
            if (matrix[r_mid][0] > target)
                r_end = r_mid -1;
            else r_start = r_mid+1;
        }


        if(r_start>r_end) return false;

        int start, end, mid;
        start = 0;
        end = n-1;
        while(start<= end){
            mid = (end-start)/2 + start;
            if(matrix[r_mid][mid] == target) return true;
            if(matrix[r_mid][mid] < target)
                start = mid +1;
            else end = mid -1;
        }
        return false;
    }
};
