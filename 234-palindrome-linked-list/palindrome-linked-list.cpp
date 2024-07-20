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
// 1 2 3 2 1
// 1 2 3 3 2 1

    ListNode* reverse(ListNode*head){
        ListNode*Next=nullptr;
        ListNode*Prev=nullptr;
        ListNode*temp=head;
        while(head){
            Next=head->next;
            head->next=Prev;
            Prev=head;
            head=Next;
        }
        return Prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode*slow=head;
        ListNode*fast=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode*rev=reverse(slow);
        ListNode*temp=head;
        while(rev){
            if(rev->val!=temp->val) return false;
            rev=rev->next;
            temp=temp->next;
        }
        return true;


    }
};