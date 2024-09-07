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
    ListNode* partition(ListNode* head, int x) {
        if(!head || !head->next) return head;
        
        ListNode* d1 = new ListNode(-1);
        ListNode* d2 = new ListNode(-1);
        ListNode* dcur1 = d1,*dcur2 = d2,*cur;
        
        cur = head;
        while(cur){
            if(cur->val<x){
                dcur1->next = cur;
                if(dcur1->next)
                    dcur1 = dcur1->next;
            }
            else{
                dcur2->next = cur;
                if(dcur2->next)
                    dcur2 = dcur2->next;
            }
            cur = cur->next;
        }
        dcur2->next = nullptr;
        dcur1->next = d2->next;
        return d1->next;
    }
};
