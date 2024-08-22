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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return nullptr;
        ListNode* tail = head;
        
        int n = 1;
        while(tail->next){
            n++;
            tail = tail->next;
        }
        
        k = k%n;
        
        if(k==0) return head;
        
        ListNode* cur = head,*temp;
        for(int i=0;i<(n-k-1);i++){
            cur = cur->next;
        }
        
        temp = cur->next;
        cur->next = nullptr;
        
        tail->next = head;
        head = temp;
        
        return head;
    }
};