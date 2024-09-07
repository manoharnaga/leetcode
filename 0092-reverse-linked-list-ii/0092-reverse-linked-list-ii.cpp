/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rev(ListNode* root){
        ListNode *prev,*cur,*next;
        prev = nullptr;
        cur = root;
        next = root->next;
        while(cur){
            cur->next = prev;
            prev = cur;
            cur = next;
            if(next) next = next->next;
        }
        return prev;
    }
    
    ListNode* reverseBetween(ListNode* head, int lval, int rval) {
        ListNode *left,*right,*lprev,*rnext;
        lprev = nullptr;
        ListNode *cur = head;
        int cnt = 1;
        while(cur){
            if(cnt==lval) break;
            lprev = cur;
            cnt++;
            cur = cur->next;
        }
        left = cur;
        
        cnt = 1;
        cur = head;
        while(cur){
            if(cnt==rval) break;
            cnt++;
            cur = cur->next;
        }
        right = cur;
        rnext = right->next;
        right->next = nullptr;
        
        // cout<<lprev->val<<" "<<left->val<<" "<<right->val<<" "<<rnext->val<<"\n";
        
        ListNode* x = rev(left);
        ListNode* trav = x;
        while(trav->next){
            // cout<<trav->val<<" ";
            trav = trav->next;
        }
        // cout<<"\n";
        trav->next = rnext;
        
        if(lprev) lprev->next = x;
        else      head = x;
        
        return head;
    }
};