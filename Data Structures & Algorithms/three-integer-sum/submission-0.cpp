class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_map<int, int> mp;
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret;
        for(int i =0; i<nums.size(); i++){
            mp[nums[i]] = i;
        }

        for(int i=0; i<nums.size(); i++){
            if(i!=0 && nums[i] == nums[i-1])
                continue;
            for(int j = i+1; j<nums.size(); j++){
                if(j!= i+1 && nums[j] == nums[j-1])
                    continue;
                if(mp[-nums[i] - nums[j]] > j){
                    vector<int> v;
                    v.push_back(nums[i]);
                    v.push_back(nums[j]);
                    v.push_back(-nums[i] - nums[j]);
                    ret.push_back(v);

                }
            }
        }
        return ret;
        
    }
};
