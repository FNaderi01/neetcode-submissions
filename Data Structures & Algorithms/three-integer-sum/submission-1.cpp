class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size(); i++) {
            if(i > 0 && nums[i] == nums[i-1]) {
                continue;
            }

            int left = i + 1;
            int right = nums.size() - 1;
            // cout<<i<<", "<<left<<", "<<right<<endl;
            while(left < right){
                int sum = nums[i] + nums[left] + nums[right];

                if(sum == 0) {
                    vector<int> a = {nums[i], nums[left], nums[right]};
                    ans.push_back(a);
                    left++;
                    while((left < right) && (nums[left] == nums[left-1])) {
                        left++;
                    }
                } else if(sum < 0) {
                    left++;
                } else {
                    right--;
                }
            }
        }

        return ans;
    }
};
