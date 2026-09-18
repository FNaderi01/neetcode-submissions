class Solution {
public:
    vector<int> multiply(vector<int>& num, int a) {
        vector<int> result;

        int carry = 0;
        for(int i = num.size() - 1; i >= 0; i--) {
            int t = num[i] * a + carry;
            result.push_back(t % 10);
            carry = (t / 10);
        }

        if(carry > 0) {
            result.push_back(carry);
        }

        reverse(result.begin(), result.end());

        // cout<<"MUL"<<endl;
        // for(int a : result) {
        //     cout<<a;
        // }
        // cout<<endl;
        return result;

    }

    void add(vector<int>& res, vector<int>& a) {
        int carry = 0;
        int i = res.size() - 1;
        int j = a.size() - 1;
        while(i >= 0 && j >= 0) {
            int t = res[i] + a[j] + carry;
            res[i] = t % 10;
            carry = t / 10;
            i--;
            j--;
        }

        if(carry != 0) {
            res[i] = carry;
        }

        // cout<<"ADD"<<endl;
        // for(int a : res) {
        //     cout<<a;
        // }
        // cout<<endl;
    }


    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0") {
            return "0";
        }
        // Always num1.size() <= num2.size()
        if(num1.size() > num2.size()) {
            swap(num1, num2);
        }

        vector<int> n1, n2;
        for(char ch : num1) {
            n1.push_back(ch - '0');
        }
        for(char ch : num2) {
            n2.push_back(ch - '0');
        }

        vector<int> result(n1.size() + n2.size(), 0);
        for(int i = n1.size() - 1; i >= 0; i--) {
            if(n1[i] != 0) {
                vector<int> dm = multiply(n2, n1[i]);
                add(result, dm);
                // break;
            }
            n2.push_back(0);
        }

        int i = 0;
        while(result[i] == 0) {
            i++;
        }
        string ans = "";
        while(i < result.size()) {
            ans += (result[i] + '0');
            i++;
        }

        return ans;
    }
};
