class Solution {
public:
    bool isPossible(int k, vector<int>& piles, int h) {
        int my_h = 0;
        for(int i = 0; i < piles.size(); i++) {
            my_h += (k + piles[i] - 1) / k;
            if(my_h > h) {
                return false;
            } 
        }
        return true;
    }

    int bsearch(int s, int e, vector<int>& piles, int h) {
        if(s > e) {
            return INT_MAX;
        }
        int mid = (e - s) / 2 + s;
        bool can = isPossible(mid, piles, h);

        if(can) {
            return min(mid, bsearch(s, mid - 1, piles, h));
        } else {
            return bsearch(mid + 1, e, piles, h);
        }
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        /* Find the range of binary search. */
        int maxPile = 0;
        for(int i : piles) {
            maxPile = max(maxPile, i);
        }

        return bsearch(1, maxPile, piles, h);
    }
};