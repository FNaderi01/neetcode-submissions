class Solution {
public:
    int find(vector<int>& nums, int l, int r, int p, int k) {

        if(l == r) {
            return nums[l];
        }

        int cur = l;
        int pValue = nums[p];
        int equal = 0;
        for(int i = l; i <= r; i++) {
            if(nums[i] >= pValue) {
                swap(nums[i], nums[cur]);
                cur++;

                equal += (nums[i] == pValue);
            }
        }

        int greEq = cur - l;
        if(greEq == k) {
            return pValue;
        }
        if(greEq > k) {
            if(greEq - equal == 0) {
                return pValue;
            }

            int newP = rand() % (cur - l) + l;
            return find(nums, l, cur - 1, newP, k);
        }
        int newP = rand() % (r - cur + 1) + cur;
        return find(nums, cur, r, newP, k - greEq);
    }

    int findKthLargest(vector<int>& nums, int k) {
        srand(time(0)) ;
        int p = rand() % (nums.size());

        return find(nums, 0, nums.size() - 1, p, k);
    }
};
