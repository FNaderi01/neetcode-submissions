#include <string>
class Solution {
public:
    string encodeChar(char c) {
        short d = c + 2;
        string res = "000";
        int i = 2;
        while(d > 0) {
            res[i] = (d % 10) + '0';
            d /= 10;
            i--;
        }
        return res;
    }

    string encodeString(string str) {
        if (str.size() == 0) {
            return "001";
        }
        string res = "";
        for(int i = 0; i < str.size(); i++) {
            res += encodeChar(str[i]);
        }
        return res;
    }

    string encode(vector<string>& strs) {
        if(strs.size() == 0) {
            return "";
        }

        string res = encodeString(strs[0]);
        for(int i = 1; i < strs.size(); i++) {
            res += "000" + encodeString(strs[i]);
        }
        return res;
    }

    char decodeString(string s) {
        short temp = (s[0] - '0') * 100 + (s[1] -'0') * 10 + s[2] - '0';
        temp -= 2;
        char res = char(temp);
        return res;
    }
    vector<string> decode(string s) {
        vector<string> res;
        if(s.size() == 0) {
            return res;
        }
        
        string tmp = "";
        for (int i = 0; i < s.size(); i += 3) {
            
            string atIdx = s.substr(i, 3);
            if (atIdx == "000") {
                if (tmp.size() > 0)
                    res.push_back(tmp);
                tmp = "";
                continue;
            } else if (atIdx == "001") {
                res.push_back("");
                tmp = "";
                continue;
            }
            
            tmp += decodeString(atIdx);
        }

        if (tmp.size() > 0) {
            res.push_back(tmp);
        }
            
        return res;
    }
};
