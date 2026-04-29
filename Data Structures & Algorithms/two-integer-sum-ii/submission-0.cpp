class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ret;
        int i, j;
        i=0;
        j = numbers.size() -1;

        while(i<j){
            if(numbers[i] + numbers[j] == target ){
                ret.push_back(i+1);
                ret.push_back(j+1);
                return ret;
            }
            if(numbers[i] + numbers[j] < target){
                i++;
                continue;
            }
            if(numbers[i] + numbers[j] > target){
                j--;
                continue;
            }
        }
        return ret;
    }
};
