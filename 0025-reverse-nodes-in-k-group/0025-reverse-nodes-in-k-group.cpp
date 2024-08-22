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
    
    void revList(ListNode* head,ListNode* tail){
        ListNode *prev = nullptr;
        ListNode *cur = head;
        ListNode *next = cur->next;
        ListNode  *tailnext = tail->next;
        
        while(cur && cur!=tailnext){
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        int n = 0;
        ListNode* cur = head,*prevend;
        while(cur){
            n++;
            cur = cur->next;
        }
        
        if(n<k) return head;
        
        int cnt = 0,maincnt = 0;
        
        int f = 1;
        ListNode *start,*end, *curend;
        curend = head;
        while(maincnt<n){
            if((n-maincnt)<k){
                prevend->next = curend;
                break;
            }
            
            start = end = curend;
            for(int i=0;i<k-1;i++){
                end = end->next;
            }
            
            curend = end->next;
            // cout<<curend->val<<curend->next->val<<"y\n";
            
            revList(start,end);
            
            
            if(f){
                head = end;
                f = 0;
            }
            else{
                prevend->next = end;
            }
            prevend = start;
            maincnt += k;
        }
        return head;
    }
};