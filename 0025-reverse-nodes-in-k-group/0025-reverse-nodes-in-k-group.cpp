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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* trav = head;
        for(int i=0;i<k;i++){
            if(!trav) return head;
            trav = trav->next;
        }
        
        ListNode* cur = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        for(int i=0;i<k;i++){
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        
        head->next = reverseKGroup(cur,k);
        return prev;
    }
};