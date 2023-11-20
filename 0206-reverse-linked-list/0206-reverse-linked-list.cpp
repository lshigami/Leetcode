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
    // ListNode* reverseList(ListNode* head) {
    //     if(head==nullptr || head->next==nullptr) return head;
    //     ListNode*B=nullptr;
    //     ListNode*F=nullptr;
    //     while(head!=nullptr){
    //         F=head->next;
    //         head->next=B;
    //         B=head;
    //         head=F;
    //     }
    //     head=B;
    //     return head;
    // }   
    ListNode* reverseList(ListNode* head) {
        ListNode*Prev=nullptr;
        ListNode*Next=nullptr;
        while(head){
            Next=head->next;
            head->next=Prev;
            Prev=head;
            head=Next;
        }
        head=Prev;
        return head;
    }

};