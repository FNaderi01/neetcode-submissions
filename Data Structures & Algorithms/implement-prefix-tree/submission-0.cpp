class PrefixTree {
    struct TreeNode {
        char value;
        unordered_map<char, TreeNode*> m;
        TreeNode(char val) : value(val) {
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
        s.insert(word);
    }
    
    bool search(string word) {
        return (s.find(word) != s.end());
    }
    
    bool startsWith(string prefix) {
        TreeNode* cur = root;
        for(char x : prefix) {
            if(cur->m.find(x) == cur->m.end()) {
                return false;
            }
            cur = cur->m[x];
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