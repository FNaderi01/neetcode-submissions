class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start, end, mid;
        start = 0;
        end = nums.size()-1;
        

        while(start<= end){
            mid = (end - start)/2 + start;
            if (nums[mid] == target) return mid;
            if (nums[mid] < target){
                start = mid + 1;
            }    
            else {
                end = mid -1;
            }
        } 
        return -1;

    }
};
