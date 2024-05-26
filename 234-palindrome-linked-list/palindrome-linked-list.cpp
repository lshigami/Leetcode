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
    ListNode* reverseLinkedList(ListNode*head){
        ListNode*Prev=nullptr;
        ListNode*Next=nullptr;
        while(head){
            Next=head->next;
            head->next=Prev;
            Prev=head;
            head=Next;
        }
        return Prev;
    }
    bool isPalindrome(ListNode* head) {
        if(head->next==nullptr) return true;
        ListNode*slow=head;
        ListNode*fast=head;
        int count=0;
        while(fast&&fast->next){
            count+=1;
            slow=slow->next;
            fast=fast->next->next;
        }
        if(slow->next==nullptr) return slow->val==head->val;
        if(fast!=nullptr) slow=slow->next;
        slow=reverseLinkedList(slow);
        while(slow){
            if(slow->val!=head->val) return false;
            slow=slow->next;
            head=head->next;
        }
        return true;
    }
};