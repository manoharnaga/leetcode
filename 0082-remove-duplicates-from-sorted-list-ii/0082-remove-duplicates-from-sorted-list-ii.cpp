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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return head;
        ListNode *prev,*cur,*next;
        prev = nullptr;
        cur = head;
        next = cur->next;
        while(next){
            int f = 0;
            while(next && cur->val==next->val){
                // cout<<cur->val<<" "<<next->val<<"x\n";
                f = 1;
                next = next->next;
            }
            if(f){
                // cout<<prev->val<<"\n";
                // cout<<cur->val<<" "<<cur->next->val<<"\n";
                if(prev){
                    prev->next = next;
                }
                else head = next;
                cur = next;
                if(next) next = next->next;
            }
            else{
                prev = cur;
                cur = next;
                next = next->next;
            }
        }
        return head;
    }
};