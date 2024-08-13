
class LRUCache {
public:
    struct Node{
        int key;
        int val;
        Node* next;
        Node* prev;
        Node(int key_,int val_){
            key = key_;
            val = val_;
        }
    };
    int n;
    map<int,Node*> mp;
    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);
    LRUCache(int capacity) {
        n = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    void addNode(Node* cur){
        Node* prev = head;
        Node* next = head->next;
        cur->next = next;
        cur->prev = prev;
        prev->next = cur;
        next->prev = cur;
        mp[cur->key] = cur;
    }

    void delNode(Node* cur){
        Node* prev = cur->prev;
        Node* next = cur->next;
        prev->next = next;
        next->prev = prev;
    }

    int get(int key) {
        if(mp.find(key)!=mp.end()){
            Node* cur = mp[key];
            delNode(cur);
            addNode(cur);
            return cur->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            Node* cur = mp[key];
            mp.erase(key);
            delNode(cur);
        }
        if(mp.size()==n){
            mp.erase(tail->prev->key);
            delNode(tail->prev);
        }
        addNode(new Node(key,value));
        mp[key] = head->next;
    }
};