class PrefixTree {
    struct TreeNode {
        char value;
        bool isEnding;
        unordered_map<char, TreeNode*> m;
        TreeNode(char val) : value(val), isEnding(false) {
        }
    };
    TreeNode* root;
    unordered_set<string> s;
public:
    PrefixTree() {
        root = new TreeNode('0');
    }
    
    void insert(string word) {
        TreeNode* cur = root;
        for(char x : word) {
            if(cur->m.find(x) == cur->m.end()) {
                cur->m[x] = new TreeNode(x);
                cur = cur->m[x];
                continue;
            }
            cur = cur->m[x];
        }
        cur->isEnding = true;
        s.insert(word);
    }
    bool generalSearch(string word, bool checkWord) {
        TreeNode* cur = root;
        for(char x : word) {
            if(cur->m.find(x) == cur->m.end()) {
                return false;
            }
            cur = cur->m[x];
        }
        if(checkWord) {
            return cur->isEnding;
        }
        return true;
    }
    bool search(string word) {
        return generalSearch(word, true);
    }
    
    bool startsWith(string prefix) {
        return generalSearch(prefix, false);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */