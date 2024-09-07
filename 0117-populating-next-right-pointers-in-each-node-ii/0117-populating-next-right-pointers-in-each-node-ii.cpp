/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void c2(Node* root,Node* r){
        if(!root || !r) return;
        // cout<<root->val<<"\n";
        while(r){
            if(r->left){
                root->next = r->left;
                return;
            }
            if(r->right){
                root->next = r->right;
                return;
            }
            r = r->next;
        }
    }
    Node* connect(Node* T) {
        if(!T) return T;
        queue<Node*> q;
        q.push(T);
        while(!q.empty()){
            Node* root = q.front();
            q.pop();
            if(root->left && root->right){
                root->left->next = root->right;
                c2(root->right,root->next);
            }
            else if(root->left){
                c2(root->left,root->next);
            }
            else if(root->right){
                c2(root->right,root->next);
            }
            if(root->left) q.push(root->left);
            if(root->right) q.push(root->right);
        }
        return T;
    }
};