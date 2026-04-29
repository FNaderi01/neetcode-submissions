class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l, r;
        int ret =0;
        l =0; 
        r = heights.size()-1;
        while(l<r){
            int area = (r-l) * min(heights[l], heights[r]);
            ret = max(ret, area);

            if(heights[l]<heights[r])
                l++;
            else r--;
        } 
        return ret;  
    }
};
