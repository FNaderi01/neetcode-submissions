class WordDictionary {
    struct TreeNode {
        char value;
        bool isEnding;
        TreeNode* arr[26];

        TreeNode(char val) : value(val), isEnding(false) {
            for(int i = 0; i < 26; i++) {
                arr[i] = NULL;
            }
        }
    };
    TreeNode* root;
public:
    WordDictionary() {
        root = new TreeNode('0');
    }
    
    void addWord(string word) {
        TreeNode* cur = root;
        int idx = 0;
        for(char x : word) {
            idx = x -'a';
            if(cur->arr[idx] == NULL) {
                cur->arr[idx] = new TreeNode(x);
            }
            cur = cur->arr[idx];
        }
        cur->isEnding = true;
    }
    
    bool search(string word) {
        return privateSearch(root, word);
    }

    bool privateSearch(TreeNode* root, string word) {
        // cout<<root->value<<" "<<word<<endl;
        char firstChar = word[0];
        if(word.size() == 1) {
            if(firstChar != '.') {
                int idx = firstChar - 'a';
                if(root->arr[idx] != NULL && root->arr[idx]->isEnding) {
                    return true;
                }
                return false;
            } else {
                for(int i = 0; i < 26; i++) {
                    if(root->arr[i] != NULL && root->arr[i]->isEnding) {
                        return true;
                    }
                }
                return false;
            }
            
        }


        if(firstChar != '.') {
            int idxFirst = firstChar - 'a';
            if(root->arr[idxFirst] != NULL) {
                return privateSearch(root->arr[idxFirst], word.substr(1, word.size() - 1));
            } else {
                return false;
            }
        } else {
            for(int i = 0; i < 26; i++) {
                if(root->arr[i] != NULL) {
                    if(privateSearch(root->arr[i], word.substr(1, word.size() - 1))) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */