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
        ListNode *temp=head;
        ListNode *prev=new ListNode(0,head);
        ListNode *af=prev;
        bool ok;
        while(temp &&temp->next){
            ok=true;
            while(temp && temp->next && temp->val==temp->next->val){
                ok=false;
                ListNode*del=temp->next;
                temp->next=temp->next->next;
                delete del;
            }
            temp=temp->next;
            if(ok==false){
                prev->next=temp;
            }
            else prev=prev->next;
        }
        return af->next;
    }
};