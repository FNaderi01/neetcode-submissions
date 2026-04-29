class Solution {
public:
    bool topCheck(vector<int>& nums1, vector<int>& nums2, int a, int b){
        if(a-1>=0 && b<nums2.size()){
           return nums1[a-1] <= nums2[b]; 
        }
        return true;
    }
    bool downCheck(vector<int>& nums1, vector<int>& nums2, int a, int b){
        if(b-1>=0 && a<nums1.size()){
          return nums2[b-1] <= nums1[a]; 
        }
        return true;
    }
    double getMedian(vector<int>& nums1, vector<int>& nums2, int a, int b) {
        int s = nums1.size() + nums2.size();
        if(s % 2 == 1) {
            if(a == nums1.size())   return nums2[b];
            if(b == nums2.size())   return nums1[a];
            return min(nums1[a], nums2[b]);
        }
        int x = 0, y = 0;
        if(a == 0) x = nums2[b-1];
        else if(b == 0) x = nums1[a-1];
        else x = max(nums1[a-1], nums2[b-1]);

        if(a == nums1.size()) y = nums2[b];
        else if(b == nums2.size()) y = nums1[a];
        else y = min(nums1[a], nums2[b]);
        return (x + y * 1.0)/2.0;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int l = 0, r = nums1.size();
        int s = (nums1.size() + nums2.size()) / 2;
        while(1) {
            int mid = (l+r)/2;
            int rem = s - mid;
            if(!topCheck(nums1, nums2, mid, rem)) {
                r = mid-1;
                continue;
            }
            if(!downCheck(nums1, nums2, mid, rem)) {
                l = mid+1;
                continue;
            }
            return getMedian(nums1, nums2, mid, rem);
        }

    }
};
