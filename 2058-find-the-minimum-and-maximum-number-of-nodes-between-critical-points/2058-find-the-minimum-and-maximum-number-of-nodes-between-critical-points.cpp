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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode *prev,*cur,*next;
        prev = head;
        cur = prev->next;
        next = cur->next;
        int start = -1,end = -1;
        int prevcnt = -1;
        int mindist = INT_MAX,maxdist = INT_MIN;
        while(next){
            int lmin = (cur->val<prev->val && cur->val<next->val);
            int lmax = (cur->val>prev->val && cur->val>next->val);
            if(lmin || lmax){
                if(start==-1){
                    start=end=1;
                }
                else{
                    mindist = min(mindist,end-prevcnt);
                    maxdist = max(maxdist,end-start);
                }
                prevcnt = end;
            }
            if(start!=-1)   end++;
            prev = cur;
            cur = next;
            next = next->next;
        }
        if(mindist==INT_MAX && maxdist==INT_MIN) return {-1,-1}; // no answer
        return {mindist,maxdist};
    }
};