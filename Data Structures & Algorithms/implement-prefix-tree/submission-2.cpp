class PrefixTree {
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
    PrefixTree() {
        root = new TreeNode('0');
    }
    
    void insert(string word) {
        TreeNode* cur = root;
        int idx = 0;
        for(char x : word) {
            idx = x - 'a';
            if(cur->arr[idx] == NULL) {
                cur->arr[idx] = new TreeNode(x);
                cur = cur->arr[idx];
                continue;
            }
            cur = cur->arr[idx];
        }
        cur->isEnding = true;
    }

    bool search(string word) {
        TreeNode* cur = root;
        int idx = 0;
        for(char x : word) {
            idx = x - 'a';
            if(cur->arr[idx] == NULL) {
                return false;
            }
            cur = cur->arr[idx];
        }
        return cur->isEnding;
    }
    
    bool startsWith(string prefix) {
        TreeNode* cur = root;
        int idx = 0;
        for(char x : prefix) {
            idx = x - 'a';
            if(cur->arr[idx] == NULL) {
                return false;
            }
            cur = cur->arr[idx];
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */