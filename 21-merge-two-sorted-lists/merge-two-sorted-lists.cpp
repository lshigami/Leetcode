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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode*a=list1;
        ListNode*b=list2;
        ListNode*res= new ListNode();
        ListNode*temp=res;
        while(a || b){
            if(a && b){
                if(a->val<=b->val){
                    ListNode*newNode= new ListNode(a->val);
                    temp->next=newNode;
                    temp=temp->next;
                    a=a->next;
                }
                else{
                    ListNode*newNode= new ListNode(b->val);
                    temp->next=newNode;
                    temp=temp->next;
                    b=b->next;
                }
            }
            else if(a){
                ListNode*newNode= new ListNode(a->val);
                temp->next=newNode;
                temp=temp->next;
                a=a->next;
            }else{
                ListNode*newNode= new ListNode(b->val);
                temp->next=newNode;
                temp=temp->next;
                b=b->next;
            }
        }
        return res->next;
    }
};