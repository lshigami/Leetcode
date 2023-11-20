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
    ListNode* swapPairs(ListNode* head) {
        if(head==nullptr) return nullptr;
        if(head->next==nullptr) return head;
        ListNode*temp=head;
        ListNode*af=head->next;
        
        while(temp && temp->next){
            ListNode*two=temp;
            Swap(temp,temp->next);
            temp=temp->next;
            if(temp==nullptr || temp->next==nullptr) return af;
            two->next=temp->next;
        }
        return af;
        
    }
    void Swap(ListNode*a,ListNode*b){
        a->next=b->next;
        b->next=a;
    }
};