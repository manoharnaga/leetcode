/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return NULL;
        
        Node* cur = head;
        Node* list,*h;
        
        map<Node*,int> m1;
        map<int,Node*> m2;
        int i = 0;
        
        list = new Node(cur->val);
        h = list;
        m1[cur] = i;
        m2[i] = list;
        
        cur = cur->next;
        
        i++;
        
        while(cur){
            Node* newNode = new Node(cur->val);
            list->next = newNode;
            
            m1[cur] = i;
            m2[i] = newNode;
            
            list = list->next;
            cur = cur->next;
            i++;
        }
        
        m1[nullptr] = i;
        m2[i] = nullptr;
        
        
        cur = head;
        list = h;
        
        while(cur){
            // cout<<m1[cur->random]<<"x\n";
            list->random = m2[m1[cur->random]];
            list = list->next;
            cur = cur->next;
        }
        
        return h;
    }
};