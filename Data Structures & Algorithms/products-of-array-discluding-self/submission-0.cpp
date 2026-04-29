class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> v, e(nums.size());
        vector<int> ret(nums.size());
        e[nums.size()-1] = 1;
        v.push_back(1);
        for(int i = 1; i<nums.size(); i++){
            v.push_back(v[i-1] * nums[i-1]);
        }

        for(int i = nums.size()-2; i>=0;i--){
            e[i] = e[i+1] * nums[i+1];
        }

        for(int i = 0; i<nums.size();i++ ){
            ret[i] = v[i] * e[i];
        }
        return ret;
    }
};
