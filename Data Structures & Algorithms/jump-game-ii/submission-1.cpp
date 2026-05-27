class Solution {
public:
    int jump(vector<int>& nums) {
        int curEnd = 0;
        int curFar = 0;
        int ans = 0;
        for(int i = 0; i < nums.size() - 1; i++) {
            curFar = max(curFar, nums[i] + i);

            if(i == curEnd) {
                curEnd = curFar;
                ans++;
            }
        }

        return ans;
    }
};
