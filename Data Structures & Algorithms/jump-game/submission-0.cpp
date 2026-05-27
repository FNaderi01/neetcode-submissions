class Solution {
public:
    bool canJump(vector<int>& nums) {
        int dest = nums.size() - 1;
        int next = dest - 1;

        while(next >= 0) {
            if(nums[next] >= (dest - next)) {
                dest = next;
                next = dest - 1;
            } else {
                next--;
            }
        }

        return (dest == 0);

    }
};
