class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int b = 0;
        for(int i=0; i<piles.size(); i++){
            b = max(b, piles[i]);
        }

        int start, end, mid=0;
        start =1;
        end = b; 
        int ans = 0;
        while(start<= end){
            mid = (end-start)/2 + start;
            int t=h;
            for(int i=0;i<piles.size(); i++){
                
                t = t- (1 + (piles[i]-1)/mid);
                if(t<0){
                    break;
                }
            }
            if(t<0){
                start = mid +1;
                // if(ans!=0) return ans;
            }
            else {
                ans = mid;
                end = mid -1;
            }
            
        }
        return ans;
    }
};
