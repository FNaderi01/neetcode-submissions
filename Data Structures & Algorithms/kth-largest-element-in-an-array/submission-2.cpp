class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        int pivot = nums[rand() % nums.size()];

        vector<int> left;
        vector<int> right;
        vector<int> mid;

        for (int n : nums) {
            if (n == pivot) {
                mid.push_back(n);
                continue;
            }
            if (n < pivot) {
                left.push_back(n);
                continue;
            }
            if (n > pivot) {
                right.push_back(n);
                continue;
            }
        }
        if (k <= right.size()) {
            return findKthLargest(right, k);
        }

        if (right.size() + mid.size() < k) {
            return findKthLargest(left, k - right.size() - mid.size());
        }
        return pivot;
    }
};