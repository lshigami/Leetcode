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
        if(head==nullptr) return nullptr;
        if(head->next==nullptr) return head;
        ListNode*temp=head;
        while(temp && temp->next){
            while(temp->next && temp->next->val==temp->val){
                ListNode *del=temp->next;
                temp->next=temp->next->next;
                delete del;
            }
            temp=temp->next;
        }
        return head;
    }
};