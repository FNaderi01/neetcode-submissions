class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pair<int, vector<int>>> v;
        vector<vector<int>> ans;
        for(vector<int> point : points) {
            int dis = (point[0] * point[0]) + (point[1] * point[1]);
            v.push_back({dis, point});
        }

        sort(v.begin(), v.end());
        int n = 0;
        while(k > 0) {
            ans.push_back(v[n].second);
            n++;
            k--;
        }

        return ans;
    }
};
