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
        int size=0;
        ListNode*temp=head;
        while(temp){
            size+=1;
            temp=temp->next;
        }
        if(size==0) return nullptr;
        temp=head;
        while(temp->next){
            temp=temp->next;
        }
        temp->next=head;
        temp=head;
        k=k%size;
        cout<<k;
        for(int i=1;i<size-k;i++){
            temp=temp->next;
        }
        ListNode*newHead=temp->next;
        temp->next=nullptr;
        return newHead;

    }
};