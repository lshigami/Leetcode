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
    ListNode* insertionSortList(ListNode* head) {
        ListNode *dummy= new ListNode(0,head);
        ListNode *cur=head;
        ListNode *prev=dummy;
        while(cur!=nullptr){
            if(cur->next && cur->next->val< cur->val){
                while(prev->next && prev->next->val<cur->next->val){
                    prev=prev->next;
                }
                ListNode*temp=cur->next->next;
                cur->next->next=prev->next;
                prev->next=cur->next;
                cur->next=temp;
                prev=dummy;
            }
            else{
                cur=cur->next;
            }
        }
        return dummy->next;
    }
};