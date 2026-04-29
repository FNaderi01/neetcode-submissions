class Solution {
public:
    int findMin(vector<int> &nums) {
        int start =0 , end = nums.size()-1, mid=0;
        if(end==0) return nums[end];

        if(nums[end]< nums[end-1])
            return nums[end];
        if(nums[0] < nums[end]) return nums[0];

        while(start<= end){
            mid = (end-start+1)/2+start;
            if(nums[mid-1] > nums[mid] && nums[mid +1] > nums[mid]) 
                return nums[mid];
            if (nums[mid] > nums[start] && nums[mid] > nums[end])
                start = mid +1;
            else end = mid -1;
            
        }
        
    }
};
