class Solution {
    unordered_map<int, bool> mp;
public:
    int getLength(int cur, vector<int>& nums) {
        if(mp.find(cur+1) == mp.end() || mp[cur+1]) {
            return 1;
        }
        mp[cur+1] = true;
        return getLength(cur + 1, nums) + 1;

    }

    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) {
            return 0;
        }

        for(int i = 0; i < nums.size(); i++) {
            mp[nums[i]] = false;
        }

        int ans = 1;
        for(int i = 0; i < nums.size(); i++) {
            int cur = nums[i];
            if(!mp[cur]) {
                while(mp.find(cur-1) != mp.end()) {
                    cur--;
                }
                mp[cur] = true;
                int tmp = getLength(cur, nums);
                ans = max(tmp, ans);
            }
        }
        return ans;
    }
};
