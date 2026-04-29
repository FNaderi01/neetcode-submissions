class KthLargest {
private:
map<int, int> m;
int k;

public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(int n:nums)
            m[n]++;
    }
    
    int add(int val) {
        m[val]++;
        int cnt=0;
        for(auto it = m.cend(); it != m.cbegin(); it--){
            auto itr = it;
            itr--;
            // cout<<itr->first<<", "<<itr->second<<endl;
            if(cnt + itr->second >= k) return itr->first;
            cnt+= itr->second;
        }
        return 0;
    }
};
