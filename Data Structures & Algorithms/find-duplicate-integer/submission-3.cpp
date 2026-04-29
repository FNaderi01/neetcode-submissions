class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        /* Under O(1) extra space constraint, we execute binary search on range [1, n]. */
        int s = 1;
        int e = nums.size();
        int mid = 0;

        while(s <= e) {
            mid = (s + e) / 2;

            int less = 0;
            int sumLess = 0;
            int more = 0;
            int sumMore = 0;
            int equal = 0;

            for(int i = 0; i < nums.size(); i++) {
                if(nums[i] < mid && nums[i] >= s && nums[i] <= e) {
                    less++;
                    sumLess += nums[i];
                }

                if(nums[i] > mid && nums[i] >= s && nums[i] <= e) {
                    more++;
                    sumMore += nums[i];
                }

                equal += (nums[i] == mid && nums[i] >= s && nums[i] <= e);
            }
            // cout<<s<<" "<<e<<endl;
            // cout<<mid<<" "<<less<<" "<<more<<" "<<equal<<endl;
            if(equal > 1) {
                return mid;
            }
            if(less > more){
                e = mid - 1;
            } else if(more > less){
                s = mid + 1;
            } else {
                int expectedLess = (mid - 1 - s + 1) * (mid - 1 + s) / 2;
                int expectedMore = (e - (mid + 1) + 1) * (mid + 1 + e) /2;

                if(sumLess != expectedLess){
                    e = mid - 1;
                } else {
                    s = mid + 1;
                }
            }
        }

        return -1;
    
    }
};
