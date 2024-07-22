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
        ListNode*dummy=new ListNode(-101,head);
        ListNode*connector=dummy;
        ListNode*temp=head;
        while(temp && temp->next){
            bool isDuplicated=false;
            ListNode*run=temp->next;
            while(run && run->val==temp->val){
                isDuplicated=true;
                run=run->next;
            }   
            if(!isDuplicated){
                connector=temp;
                temp=run;
            }
            else{
                temp=run;
                connector->next=temp;
            }
        }
        return dummy->next;
    }
};