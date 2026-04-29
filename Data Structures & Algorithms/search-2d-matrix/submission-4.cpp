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
        for(int i = 0; i < matrix.size(); i++) {
            if(bsearch(0, matrix[i].size() - 1, matrix[i], target)) {
                return true;
            }
        }
        return false;
    }
};
