class Solution {
public:
    int isPossible(vector<int>& piles, int k, int h) {
        int hours = 0;
        for(int i = 0; i < piles.size(); i++) {
            if(piles[i] <= k) {
                hours++;
            } else {
                hours += (piles[i] / k) + (piles[i] % k != 0 ? 1 : 0);
            }
        }

        return hours;
    } 
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        sort(piles.begin(), piles.end());
        int maxPile = piles[n - 1];

        int s = 1;
        int e = maxPile;
        int k = INT_MAX;
        while(s <= e) {
            int mid = (s + e) / 2;
            int hours = isPossible(piles, mid, h);

            if(hours <= h) {
                k = min(k, mid);
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }

        return k;
    }
};
