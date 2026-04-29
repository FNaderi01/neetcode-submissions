class Solution {
public:
    int bsearch(int s, int e, vector<int>& nums, int target) {
        if(s > e){
            return -1;
        }

        int mid = (e-s)/2 + s;
        if(nums[mid] == target) {
            return mid;
        }
        if(nums[mid] > target) {
            return bsearch(s, mid - 1, nums, target);
        }
        return bsearch(mid + 1, e, nums, target);
    }
    int search(vector<int>& nums, int target) {
        return bsearch(0, nums.size() - 1, nums, target);
    }
};
