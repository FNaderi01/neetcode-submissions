class Solution {
priority_queue<int> maxHeap;

public:
    int lastStoneWeight(vector<int>& stones) {
        for(int n:stones){
            maxHeap.push(n);
        }
        while(maxHeap.size() > 1){
            int a = maxHeap.top();
            maxHeap.pop();
            int b = maxHeap.top();
            maxHeap.pop();
            if(a!=b){
                maxHeap.push(abs(a-b));
            }
        }
        if(maxHeap.size()==1) return maxHeap.top();
        else return 0;
    }
};
