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
    bool isPalindrome(ListNode* head) {
        if(!head->next) return true;
        
        int n = 0;
        ListNode *slow,*fast,*prev,*cur,*next2;
        cur = head;
        
        while(cur){
            n++;
            cur = cur->next;
        }
        
        prev = nullptr;
        cur = head;
        next2 = head->next;
        
        fast = head;
        while(fast && fast->next){
            // cout<<fast->val<<" "<<fast->next->val<<"\n";
            
            fast = fast->next->next;
            cur->next = prev;
            prev = cur;
            cur = next2;
            if(next2) next2 = next2->next;
        }
        
        if(n%2) cur = cur->next;
        while(prev && cur){
            if(prev->val!=cur->val) return false;
            prev = prev->next;
            cur = cur->next;
        }
        if(cur || prev) return false;
        return true;
    }
};