class Solution {
public:
    int findMin(vector<int> &nums) {
        if(nums.size() == 1) {
            return nums[0];
        }
        int s = 0;
        int e = nums.size() - 1;

        while(s <= e) {
            if(nums[s] < nums[e]) {
                return nums[s];
            }
            int mid = (e + s) / 2;

            if(mid == 0) {
                if(nums[mid] < nums[mid + 1]) {
                    return nums[mid];
                }
                s = mid + 1;
                continue;
            }

            if(mid == nums.size() - 1) {
                if(nums[mid] < nums[mid - 1]) {
                    return nums[mid];
                }
                e = mid - 1;
                continue;
            }



            if((mid - 1 >= 0 && nums[mid] < nums[mid - 1]) && 
               (mid + 1 < nums.size() && nums[mid] < nums[mid + 1])) {
                return nums[mid];
            }

            if(nums[mid] <= nums[s] && nums[mid] <= nums[e]) {
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        return 0;
    }
};
