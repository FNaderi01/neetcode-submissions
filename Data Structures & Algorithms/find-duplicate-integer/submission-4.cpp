class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int s = 1;
        int e = nums.size() -1;
        int mid = 0;
        while(s <= e) {
            if(s == e) {
                return s;
            }
            mid = (s + e) / 2;
            int lessEqual = 0;
            for(int x : nums) {
                lessEqual += (x <= mid);
            }

            if(lessEqual > mid) {
                e = mid;
            } else {
                s = mid + 1;
            }
        }
        return mid;
    }
};
