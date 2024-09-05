/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* rec(vector<vector<int>>& a,int si,int ei,int len){
        Node* root = new Node(1,1);
        int one=1,zero=1;
        for(int i=si;i<si+len;i++){
            for(int j=ei;j<ei+len;j++){
                if(a[i][j]) zero = 0;
                else one = 0;
                if(!one && !zero) break;
            }
            if(!one && !zero) break;
        }
//         cout<<len<<"\n";
//         cout<<si<<" "<<ei<<" "<<one<<" "<<zero<<"\n";
        
        if(one || zero){
            if(one) root->val = 1;
            else    root->val = 0;
            return root;
        }
        root->isLeaf = 0;
        len/=2;
        Node* topLeft = rec(a,si,ei,len);
        Node* topRight = rec(a,si,ei+len,len);
        Node* bottomLeft = rec(a,si+len,ei,len);
        Node* bottomRight = rec(a,si+len,ei+len,len);
        root->topLeft = topLeft;
        root->topRight = topRight;
        root->bottomLeft = bottomLeft;
        root->bottomRight = bottomRight;
        return root;
    }
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        return rec(grid,0,0,n);
    }
};