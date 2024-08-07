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
        ListNode*list3=new ListNode();
        ListNode*n3=list3;
        while(list1 && list2){
            ListNode*newNode=new ListNode();
            if(list1->val < list2->val) {
                newNode->val=list1->val;
                list1=list1->next;
                n3->next=newNode;
                n3=n3->next;
            }
            else{
                newNode->val=list2->val;
                list2=list2->next;
                n3->next=newNode;
                n3=n3->next;
            }
        }
        n3->next= (list1) ? list1 : list2;
        return list3->next;
    }
};