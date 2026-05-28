class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize != 0) {
            return false;
        }
        map<int, int> m;
        for(int i = 0; i < hand.size(); i++) {
            m[hand[i]]++;
        }
        // cout<<"size of m: "<<m.size()<<endl;
        while(!m.empty()) {
            auto it = m.begin();
            int key = it->first;
            int valus = it->second;

            m[key]--;
            if(m[key] == 0) {
                m.erase(key);
            }

            for(int i = key + 1; i < key + groupSize; i++) {
                if(m.find(i) == m.end()) {
                    return false;
                }

                m[i]--;
                if(m[i] == 0) {
                    m.erase(i);
                }
            }
        }

        return true;
    }
};
