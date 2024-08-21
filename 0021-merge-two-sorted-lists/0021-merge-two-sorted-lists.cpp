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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
//         ListNode *p1,*c1,*n1;
//         p1 = nullptr;
//         c1 = l1;
//         n1 = l1->next;
        
//         ListNode *p2,*c2,*n2;
//         p2 = nullptr;
//         c2 = l2;
//         n2 = l2->next;
        
//         while(c1 && c2){
//             if(c1->val<=c2->val){
//                 // p1->c1->c2->n1
//                 // jump to n1
//                 c1->next = c2;
//                 c2->next = n1;
//                 c1 = n1;
//                 if(n1) n1 = n1->next;
//             }
//             else{
//                 // p1->c2->c1->n1
//                 // jump to n2
//                 if(p1)  p1->next = c2;
//                 c2->next = c1;
//                 c2 = n2;
//                 if(n2) n2 = n2->next;
//             }
//         }
//         if(c2){
//             p1->next = c2;
//         }
        // return l1;
//         while(c2){
            
//         }
        
        ListNode *head, *cur;
        if(l1 == nullptr) {
            head = l2;
            return head;
        }
        if(l2 == nullptr) {
            head = l1; 
            return head;
        }
        // cout<<(l1->val)<<" "<<(l2->val)<<endl;
        if(l1->val < l2->val) {
            head = l1; cur = l1;
            l1 = l1->next;
        }
        else {
            head = l2; cur = l2;
            l2 = l2->next;
        }
        
        // while(cur){
        //     cout<<cur->val<<" ";
        //     cur = cur->next;
        // }
        // cout<<endl; 
        
        while(l1 != nullptr && l2 != nullptr){
            cout<<l1->val<<" "<<l2->val<<endl; 
            if(l1->val < l2->val){
                cur->next = l1;
                l1 = l1->next;
                // cur = cur->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        
        while(l1){
            cur -> next = l1; 
            l1 = l1 -> next;
            cur = cur -> next;
        }
        
        while(l2 != nullptr){
            cur -> next = l2; 
            l2 = l2 -> next;
            cur = cur -> next;
        }
        
        return head; 
            
    }
};