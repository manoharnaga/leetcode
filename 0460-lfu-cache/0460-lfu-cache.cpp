
class LFUCache {
public: 
    struct Node{
        int key;
        int val;
        int cnt;
        Node* next;
        Node* prev;
        Node(int key_,int value_){
            cnt = 1;
            key = key_;
            val = value_;
            next = prev = nullptr;
        }
    };
    
    int n;
    map<int,Node*> m;
    map<int,pair<Node*,Node*>> c;
    // unordered_map<int,Node*> delm;
    
    LFUCache(int capacity) {
        n = capacity;
    }
    
    pair<Node*,Node*> create(){
        Node* head = new Node(-1,-1);
        Node* tail = new Node(-1,-1);
        head->next = tail;
        tail->prev = head;
        return {head,tail};
    }

    void addNode(Node* cur){
        if(c.find(cur->cnt)==c.end()){
            c[cur->cnt] = create();
        }
        Node* head = c[cur->cnt].first;
        Node* next = head->next;
        cur->next = next;
        next->prev = cur;

        head->next = cur;
        cur->prev = head;
        m[cur->key] = cur;
    }

    void delNode(Node* cur){
        Node* prev = cur->prev;
        Node* next = cur->next;
        prev->next = next;
        next->prev = prev;
        
        Node* head = c[cur->cnt].first;
        Node* tail = c[cur->cnt].second;
        if(head->next==tail && tail->prev==head){
            c.erase(cur->cnt);
        }
    }

    int get(int key) {
        // cout<<key<<"get\n";
        // for(auto it: m) cout<<it.first<<"x\n";
        // for(auto it: c) cout<<it.first<<"y\n";
        if(m.find(key)!=m.end()){
            // cout<<"yes\n";
            Node* cur = m[key];
            delNode(cur);
            cur->cnt++;
            addNode(cur);
            // cout<<cur->cnt<<cur->val<<"heyaa\n";
            return cur->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        // cout<<"put"<<key<<" "<<value<<"\n";
        if(m.find(key)!=m.end()){
            Node* cur = m[key];
            delNode(cur);
            cur->cnt++;
            cur->val = value;
            addNode(cur);
        }
        else{
            if(m.size()==n){
                // for(auto it: c){
                //     cout<<it.first<<"kkk\n";
                // }
                Node* tail = c.begin()->second.second;
                // cout<<tail->prev->key<<"kk2\n";
                m.erase(tail->prev->key);
                delNode(tail->prev);
            }
            Node* newNode = new Node(key,value);
            addNode(newNode);
        }
        // for(auto it: m) cout<<it.first<<"x\n";
        // for(auto it: c) cout<<it.first<<"y\n";
    }
};