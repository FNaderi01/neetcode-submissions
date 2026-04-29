typedef pair<int, int> pd;

class Solution {
struct myComp {
     bool operator()(
        pair<int, int> const& a,
        pair<int, int> const& b)
        const noexcept
    {   
        int t1 = ((a.first)*(a.first) + (a.second)*(a.second));
        int t2 = ((b.first)*(b.first) + (b.second)*(b.second));
        cout<<t1<<endl;
        cout<<t2<<endl;
        return t1 < t2;
    }
};

public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pd, vector<pd>, myComp> p1;

        for(auto x: points){
            p1.push({x[0], x[1]});
            if(p1.size()>k)
                p1.pop();
        }
        vector<vector<int>> ret;
        while(p1.size()){
            auto x = p1.top();
            ret.push_back({x.first, x.second});
            p1.pop();
        }
        return ret;
    }
};
