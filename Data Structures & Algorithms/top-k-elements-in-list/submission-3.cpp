class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(int i=0; i< nums.size(); i++){
            mp[nums[i]]++;
        }
        vector<vector<int>> v(nums.size()+1);
        // cout<<v[0][0]<<endl;
        // for(int i=0; i<v.size();i++) cout<<v[i].size()<<endl;
        for (const auto& pair : mp) {
            // cout<<pair.first<<","<<pair.second<<endl;
            v[pair.second].push_back(pair.first);
        }
        // for(int i=0; i<v.size();i++) cout<<v[i].size()<<endl;

    vector<int> ret;
    for(int i = nums.size();i>0, k>0;){

        while(v[i].size() == 0 && i>0)
            i--;

        // cout<<v[i][1]<<endl;    
        if(i>0){
            cout<<v[i].size()<<endl;
            for(int j=0; j<v[i].size() && k>0;j++,k-- ){
                cout<<v[i][j]<<endl;
                ret.push_back(v[i][j]);
            }
        }
        else break;
        i--;

    }
    return ret;
}
};
