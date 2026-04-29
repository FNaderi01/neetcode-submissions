class LRUCache {
    struct LRUNode {
        LRUNode* prev;
        LRUNode* next;
        int key;
        LRUNode(int theKey) {
            key = theKey;
            prev = nullptr;
            next = nullptr;
        }
    };

    struct LRUList {
        LRUNode* head;
        LRUNode* tail;

        LRUList() : head(NULL), tail(NULL) {

        }

        void add(LRUNode* newNode) {
            // cout<<"Add "<<newNode->key<<endl;
    
            if(head == NULL) {
                head = newNode;
                tail = newNode;
            } else {
                head->prev = newNode;
                newNode->next = head;
                head = newNode;
            }

            // print();
        }

        void remove(LRUNode* node) {
            // cout<<"REMOVE "<<node->key<<endl;
            if(node == head) {
                head = head->next;
                // print();
                return;
            } else if(node == tail) {
                tail = tail->prev;
                tail->next = NULL;
                // print();
                return;
            }


            LRUNode* p = node->prev;
            LRUNode* n = node->next;

            p->next = n;
            n->prev = p;
            

            // print();
        }

        void update(LRUNode* node) {
            // cout<<"UPDATE "<<node->key<<endl;
            
            remove(node);
            add(node);

            // print();
        }

        void print() {
            LRUNode* cur = head;
            while(cur != NULL) {
                // cout<<cur->key<<"||";
                cur = cur->next;
            }
            // cout<<"END PRINT"<<endl;
        }
    };
    unordered_map<int, pair<int, LRUNode*>> mp;
    LRUList lruList;
    int cap;
public:
    LRUCache(int capacity) {
        cap = capacity;
        lruList.head = NULL;
        lruList.tail = NULL;
    }
    
    int get(int key) {
        // cout<<"================================"<<endl;
        // cout<<"OPREATION GET "<<key<<endl;
        if(mp.find(key) == mp.end()) {
            return -1;
            // cout<<"================================"<<endl;
        }
        auto pair_val = mp[key];
        lruList.update(pair_val.second);
        return pair_val.first;
        // cout<<"================================"<<endl;
    }
    
    void put(int key, int value) {
        // cout<<"================================"<<endl;
        // cout<<"OPERATION PUT "<<key<<endl;
        if(mp.find(key) == mp.end()) {
            if(mp.size() < cap) {
                LRUNode* newNode = new LRUNode(key);
                lruList.add(newNode);
                mp[key] = make_pair(value, newNode);
            } else {
                // cout<<"Need to evict "<<lruList.tail->key<<endl;
                mp.erase(lruList.tail->key);
                lruList.remove(lruList.tail);

                LRUNode* newNode = new LRUNode(key);
                lruList.add(newNode);
                mp[key] = make_pair(value, newNode);
            }
        } else {
            auto pair_val = mp[key];
            lruList.update(pair_val.second);
            mp[key].first = value;
        }
        // cout<<"================================"<<endl;
    }
};
