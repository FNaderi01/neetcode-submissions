class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        
        uint32_t ans =0;
        uint32_t p =1;
        for(int k=31; k>=0; k--){

            if((1<<k) & n){
                ans += p;
            }
            p*=2;
        }
        return ans;
    }
};
