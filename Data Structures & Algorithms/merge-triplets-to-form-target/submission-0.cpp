class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool x = false;
        bool y = false;
        bool z = false;

        for(int i = 0; i < triplets.size(); i++) {
            int a = triplets[i][0];
            int b = triplets[i][1];
            int c = triplets[i][2];

            if(a == target[0] && b <= target[1] && c <= target[2]) {
                x = true;
            }
            if(a <= target[0] && b == target[1] && c <= target[2]) {
                y = true;
            }
            if(a <= target[0] && b <= target[1] && c == target[2]) {
                z = true;
            }
        }

        return (x && y && z);
    }
};
