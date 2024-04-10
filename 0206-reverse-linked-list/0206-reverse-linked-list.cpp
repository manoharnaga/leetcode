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
    ListNode* reverseList(ListNode* head) {
        if(!head) return nullptr;
        if(!head->next) return head;
        ListNode* prev = head;
        ListNode* cur = head->next;
        ListNode* next = head->next->next;
        prev->next = nullptr;
        while(next){
            // cout<<prev->val<<" "<<cur->val<<" "<<next->val<<"X";
            cur->next = prev;
            prev = cur;
            cur = next;
            next = next->next;
            cout<<prev->val<<" "<<cur->val<<" "<<"\n";
        }
        if(cur){
            cur->next = prev;
        }
        return cur;
    }
};