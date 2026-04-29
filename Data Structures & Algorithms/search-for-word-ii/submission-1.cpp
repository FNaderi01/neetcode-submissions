class Solution {
    struct Node {
        Node* arr[26];
        bool isEnding;
        int accessed = 0;
    };

    struct Trie {
        Node* root;
        Trie() {
            root = new Node();
        }

        void insert(string word) {
            Node* cur = root;
            for(char ch : word) {
                int idx = ch - 'a';
                if(cur->arr[idx] == NULL) {
                    cur->arr[idx] = new Node();
                }
                cur = cur->arr[idx];
            }
            cur->isEnding = true;
        }

        bool search(string word, int& cnt) {
            Node* cur = root;
            for(char ch : word) {
                int idx = ch - 'a';
                if(cur->arr[idx] == NULL) {
                    return false;
                }
                cur = cur->arr[idx];
            }

            if(cur->isEnding) {
                cnt = cur->accessed;
                cur->accessed++;
            } else {
                cnt = -1;
            }
            return cur->isEnding;
        }
        bool isPrefix(string word) {
            Node* cur = root;
            for(char ch : word) {
                int idx = ch - 'a';
                if(cur->arr[idx] == NULL) {
                    return false;
                }
                cur = cur->arr[idx];
            }
            return true;
        }
    };
public:
    void find(int i, int j, Trie& trie, vector<vector<char>>& board, vector<vector<bool>>& mark, vector<string>& ans, string& s) {
        mark[i][j] = true;
        s.push_back(board[i][j]);
        // cout<<s<<endl;
        int cnt = 0;
        if(trie.search(s, cnt)) {
            if(cnt == 0) {
                ans.push_back(s);
            }
        } else if(trie.isPrefix(s) == false) {
            s.pop_back();
            mark[i][j] = false;
            // cout<<"here"<<endl;
            return;
        }
        // } else if(!trie.isPrefix(s)) {
        //     s.pop_back();
        //     mark[i][j] = false;
        // }

        int n = board.size();
        int m = board[0].size();

        if(i - 1 >= 0 && !mark[i - 1][j]) {
            find(i - 1, j, trie, board, mark, ans, s);
        }
        if(i + 1 < n && !mark[i + 1][j]) {
            find(i + 1, j, trie, board, mark, ans, s);
        }
        if(j - 1 >= 0 && !mark[i][j - 1]) {
            find(i, j - 1, trie, board, mark, ans, s);
        }
        if(j + 1 < m && !mark[i][j + 1]) {
            find(i, j + 1, trie, board, mark, ans, s);
        }

        s.pop_back();
        mark[i][j] = false;

    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> ans;
        Trie trie;
        for(string s : words) {
            trie.insert(s);
        }

        vector<vector<bool>> mark(board.size(), vector<bool>(board[0].size(), false));
        string s = "";
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                find(i, j, trie, board, mark, ans, s);
            }
        }

        
        return ans;
    }
};