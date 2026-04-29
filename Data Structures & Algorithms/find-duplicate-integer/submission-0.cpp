class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // if(nums.size() == 2) return nums[0];
        int left = 1, right = nums.size()-1;

        while(left<=right){
            if (left==right) return left;
            int mid = (left+right)/2;
            int cnt=0;
            for(int x:nums){
                if (x<=mid) cnt++;
            }
            if(cnt > mid) right = mid;
            else left = mid +1;
        } 
        return 0;
    }
};
