class Solution {
public:
    int findMin(vector<int> &nums) {
        int start =0 , end = nums.size()-1, mid=0;
        if(end==0) return nums[end];

        if(nums[end]< nums[end-1])
            return nums[end];
        if(nums[0] < nums[end]) return nums[0];
        int ans =1e5+10;
        while(start<= end){
            mid = (end+start)/2;
            if(nums[start]<nums[end]){
                ans = min(ans, nums[start]);
                break;
            } 

            ans = min(ans, nums[mid]);
            cout<<ans<<endl;
            if (nums[mid] >= nums[start] )
                start = mid +1;
            else end = mid -1;
            
        }
        return ans;
        
    }
};







// class Solution {
// public:
//     int findMin(vector<int> &nums) {
//         int start =0 , end = nums.size()-1, mid=0;
//         if(end==0) return nums[end];

//         if(nums[end]< nums[end-1])
//             return nums[end];
//         if(nums[0] < nums[end]) return nums[0];
//         int ans = nums[0];
//         while(start<= end){
//             mid = (end-start)/2+start;
//             // if(nums[mid-1] > nums[mid] && nums[mid +1] > nums[mid]) 
//             //     return nums[mid];
//             if(nums[start] < nums[end]){
//                 return min(nums[start], ans);
//             }
//             ans = min(ans, nums[mid]);
//             if(nums[start] <= nums[mid] ){
//                 start = mid+1;
//             }
//             else {
//                 end = mid-1;
//             }
            
//         }
//         return ans;
//     }
// };
