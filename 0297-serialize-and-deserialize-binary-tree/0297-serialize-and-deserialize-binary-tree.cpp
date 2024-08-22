/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "N";
        string s;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            TreeNode* cur = q.front();
            q.pop();
            if(cur){
                string add = to_string(cur->val);
                s+=add;
                s+="D";
                int l = 0,r = 0;
                if(cur->left){
                    l = 1;
                    q.push(cur->left);
                }
                if(cur->right){
                    r = 1;
                    q.push(cur->right);
                }
                s+=(to_string(l)+"D"+to_string(r));
                s+="K";
            }
            else{
                s += "|";
                if(!q.empty()){
                    q.push(NULL);
                }
            }
        }
        return s;
    }

    
    queue<pair<TreeNode*,vector<int>>> rec(string& s,int ind){
        queue<pair<TreeNode*,vector<int>>> q,childq,storeq;
        while(s[ind]!='|'){
            int start = ind;
            while(s[ind]!='D') ind++;
            string num = s.substr(start,ind-start);
            // cout<<num<<"s\n";
            int rval = stoi(num);
            ind++;
            // cout<<s[ind]<<"k\n";
            int l = s[ind]-'0';
            ind+=2;
            int r = s[ind]-'0';
            // cout<<s[ind]<<"y\n";
            ind+=2;
            // cout<<s[ind]<<"h\n";
            TreeNode* cur = new TreeNode(rval);
            q.push({cur,{l,r}});
        }
        ind++;
        if(ind>=s.size()) return q;

        storeq = q;
        childq = rec(s,ind);
        
        while(!q.empty()){
            TreeNode* cur = q.front().first;
            int l = q.front().second[0];
            int r = q.front().second[1];
            q.pop();
            if(l){
               cur->left = childq.front().first;
               childq.pop();
            }
            if(r){
                cur->right = childq.front().first;
                childq.pop();
            }
        }
        return storeq;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string s) {
        cout<<s<<"\n";
        if(s[0]=='N') return NULL;
        queue<pair<TreeNode*,vector<int>>> ans = rec(s,0);
        return ans.front().first;
    }
};
// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));