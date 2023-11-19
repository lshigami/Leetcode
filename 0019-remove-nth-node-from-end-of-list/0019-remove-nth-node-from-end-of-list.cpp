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
    ListNode* removeNthFromEnd(ListNode* head, int k) {
        if(head==nullptr || head->next==nullptr) return nullptr;
        ListNode*temp=head;
        int n=0;
        while(temp){
            n++;
            temp=temp->next;
        }
        if(k==n) return head->next;
        temp=head;
        for(int i=1;i<n-k;i++){
            temp=temp->next;
        }
        ListNode *del=temp->next;
        temp->next=temp->next->next;
        delete del;
        return head;
    }
};