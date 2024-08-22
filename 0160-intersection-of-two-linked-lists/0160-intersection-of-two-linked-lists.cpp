/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *head1, ListNode *head2) {
        ListNode* n1 = head1;
        ListNode* n2 = head2;
        
        while(n1!=n2){
            n1 = (n1==NULL) ? head2: n1->next;
            n2 = (n2==NULL) ? head1: n2->next;
        }
        
        return n1;
    }
};