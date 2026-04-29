class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        vector<pair<int, int>> pairs;
        vector<int> res;
        for(int i=0; i< nums.size(); i++){
            mp[nums[i]]++;
        }

        for (const auto& pair : mp) {
            pairs.push_back(pair);
        }

    // Sort the vector based on the values (second element of the pair)
        std::sort(pairs.begin(), pairs.end(), [](const auto& a, const auto& b) {
            return a.second > b.second;
        });
        for(int i =0; i<k; i++){
            res.push_back(pairs[i].first);
        }
        return res;
    }
};
