class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ret =0;
        unordered_set<int> s,p;        

        for(int i=0; i<nums.size(); i++){
            s.insert(nums[i]);
        }
        
        int i=0;
        while(i< nums.size()){
            if(p.find(nums[i]) == p.end()){
                int k=1;
                p.insert(nums[i]);
                int x =0;
                x = nums[i]+1;
                while(s.find(x) != s.end()){
                    p.insert(x);
                    x = x+1;
                    k++;
                }
                x = nums[i] -1;

                while(s.find(x)!= s.end()){
                    p.insert(x);
                    x = x-1;
                    k++;
                }
                ret = max(ret, k);
            }
            i++;
        }
        return ret;
    }
};
