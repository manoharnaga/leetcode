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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *even,*odd;
        even = head;
        odd = head->next;
        ListNode* oddHead = odd;
        while(odd){
            even->next = odd->next;
            if(!even->next){
                break;
            }
            even = even->next;
            
            odd->next = even->next;
            odd = odd->next;
        }
        // cout<<even->val<<" "<<head->val<<"\n";
        even->next = oddHead;
        return head;
    }
};