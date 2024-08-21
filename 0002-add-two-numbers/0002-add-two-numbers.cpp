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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum,carry;
        sum = carry = 0;
        ListNode* main=l2;
        ListNode *prev;
        
        while(l1 && l2){
            sum = l1->val+l2->val+carry;
            l2->val = sum%10;
            carry = sum/10;
            l1 = l1->next;
            prev = l2;
            l2 = l2->next;
        }
        if(l1){
            prev->next = l1;
            l2 = l1;
        }
        while(l2 && carry>0){
            sum = l2->val+carry;
            // cout<<sum<<"\n";
            l2->val = sum%10;
            carry = sum/10;
            prev = l2;
            l2 = l2->next;
        }
        if(carry>0){
            prev->next = new ListNode(carry);
        }
        return main;
    }
};