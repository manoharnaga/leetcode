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
    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* cur = nullptr,*temp;
        while(head != slow){
            temp = head->next;
            head->next = cur;
            cur = head;
            head = temp;
        }
        head = cur;
        int ans = 0;
        while(slow){
            cout<<head->val<<" "<<slow->val<<"\n";
            ans = max(ans,head->val+slow->val);
            head = head->next;
            slow = slow->next;
        }
        return ans;
    }
};