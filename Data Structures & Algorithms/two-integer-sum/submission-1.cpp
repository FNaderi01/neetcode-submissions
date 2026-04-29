class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret;
        unordered_map<int, int> mp;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]] = i;
        }
        for(int i=0; i<nums.size(); i++){
            int x = target - nums[i];
            if(mp.find(x) != mp.end() && mp[x] != i){
                ret.push_back(i);
                ret.push_back(mp[x]);
                return ret;
            } 
        }        
    }
};
