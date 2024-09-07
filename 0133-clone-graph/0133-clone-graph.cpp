/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    vector<Node*> vist;
    Node* rec(Node* h){
        if(vist[h->val]){
            return vist[h->val];
        }
        Node* root = new Node(h->val);
        vist[h->val] = root;
        
        for(Node* child: h->neighbors){
            root->neighbors.push_back(rec(child));
        }
        
        return root;
    }
    Node* cloneGraph(Node* node) {
        if(!node) return node;
        vist = vector<Node*>(110,nullptr);
        return rec(node);
    }
};