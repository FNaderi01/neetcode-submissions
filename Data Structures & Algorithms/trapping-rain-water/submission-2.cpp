class Solution {
public:
    int trap(vector<int>& height) {
        int l, r;
        l =0; 
        r = height.size()-1;
        int max_r, max_l;
        max_l =height[0];
        max_r = height[r];
        int ans=0;
        int pt=0;
        while(l<r){
            if(max_l<max_r)
                pt = l+1;
            else pt = r-1;

            ans+= max(0, min(max_l, max_r) - height[pt] );
            if(max_l <max_r){
                l+=1;
                max_l = max(max_l, height[l]);
            }
            else{
                r-=1;
                max_r = max(max_r, height[r]);
            }
        }
        return ans;
    }
};