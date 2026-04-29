class Solution {
public:
    bool isAnagram(string s, string t) {
        int s_count[30];
        int t_count[30];

        for(int i=0; i<30;i++){
            s_count[i] =0;
            t_count[i] =0;
        }

        for(int i=0; i<s.size(); i++){
            int temp = int(s[i]-'a');
            s_count[temp]++;
        }
        for(int i=0; i<t.size();i++){
            int temp = t[i] - 'a';
            t_count[temp]++;
        }

        for(int i=0; i<30; i++){
            if(s_count[i] != t_count[i])
                return false;
        }
        return true;
    }
};
