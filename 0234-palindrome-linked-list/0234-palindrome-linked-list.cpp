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
    int getSize(ListNode* head){
        ListNode* cur = head;
        int n = 0;
        while(cur){
            n++;
            cur = cur->next;
        }
        return n;
    }
    bool isPalindrome(ListNode* head) {
        if(!head->next)         return true;
        if(!head->next->next)   return (head->val==head->next->val);
        
        int n = getSize(head);
        if(n==3)    return (head->val==head->next->next->val);
        
        ListNode *cur,*prev,*next2;
        prev = nullptr;
        cur = head;
        next2 = cur->next;
        
        for(int i=0;i<(n/2);i++){
            // cout<<i<<" "<<cur->val<<" "<<next2->val<<" k1\n";
            next2 = cur->next;
            cur->next = prev;
            prev = cur;
            if(i<(n/2)-1) cur = next2;
            // cout<<i<<" "<<cur->val<<" "<<next2->val<<" k2\n";
        }
        
        if(n%2) next2 = next2->next;
        // cout<<n<<"\n";
        // cout<<cur->val<<" "<<cur->next->val<<" "<<next2->val<<"\n";
        
        
        while(cur && next2){
            if(cur->val!=next2->val) return false;
            cur = cur->next;
            next2 = next2->next;
        }
        // cout<<"hyeaa\n";
        if(cur || next2) return false;
        // cout<<"hoyaa\n";
        return true;
    }
};