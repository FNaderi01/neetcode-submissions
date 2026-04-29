class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> maxLeft(nums.size(), 0);
        vector<int> maxRight(nums.size(), 0);

        for(int i = 0; i < nums.size(); i++) {
            if(i % k == 0) {
                maxLeft[i] = nums[i];
            } else {
                maxLeft[i] = max(maxLeft[i-1], nums[i]);
            }
        }

        // for(int x : maxLeft) {
        //     cout<<x<<" ";
        // }
        // cout<<endl;

        for(int i = nums.size() - 1; i >= 0; i--) {
            if(i % k == 0 || i == nums.size() - 1) {
                maxRight[i] = nums[i];
                // maxRight.push_back(nums[i]);
            } else {
                maxRight[i] = max(maxRight[i+1], nums[i]);
                // maxRight.push_back(max(maxRight[i+1], nums[i]));
            }
        }

        // for(int x : maxRight) {
        //     cout<<x<<" ";
        // }
        // cout<<endl;

        vector<int> ans;

        for(int i = k - 1; i < nums.size(); i++) {
            ans.push_back(max(maxRight[i - k + 1], maxLeft[i]));
        }

        return ans;
    }
};
