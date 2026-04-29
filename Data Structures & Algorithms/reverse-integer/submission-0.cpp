class Solution {
private:
    const int MAX_32[10] = {2,1,4,7,4,8,3,6,4,7};
    const int MIN_32[10] = {2,1,4,7,4,8,3,6,4,8};

    bool isLess(vector<int> &a, bool sign){
        if(a.size() < 10) return true;
        if(sign){
            for(int i=0; i<a.size();i++){
                if(a[i] > MAX_32[i]) return false;
            }
        }
        if(!sign){
            for(int i=0; i<a.size();i++){
                if(a[i] > MIN_32[i]) return false;
            }
        }
        return true;
    }
    

public:
    int reverse(int x) {
        if(x==0) return 0;

        vector<int> digits;
        int sign = x/(abs(x));
        int y = x/sign;
        while(y >0){
            digits.push_back(y%10);
            y= y /10;
        }
        // std::reverse(digits.begin(), digits.end());
        if(isLess(digits, sign )){
            int res =0;
            for(int z : digits){
                res += z;
                res*=10;
            }
            res/=10;
            return res*sign;
        }
        return 0;
    }
};
