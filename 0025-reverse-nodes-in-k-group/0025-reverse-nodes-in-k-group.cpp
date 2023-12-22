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
        ListNode *x = head, *y = head;
        while(x){
            vector<int> v;
            while(x && v.size()<k){
                v.push_back(x->val);
                x = x->next;
            }
            x = y;
            if(v.size()!=k) break;
            for(int i=v.size()-1;i>=0;i--){
                x->val = v[i];
                x = x->next;
            }
            y = x;
        }
        return head;
    }
};