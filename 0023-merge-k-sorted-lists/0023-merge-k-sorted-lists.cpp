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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return nullptr;
        if(lists.size()==1) return lists[0];
        ListNode*head=mergeTwoLists(lists[0],lists[1]);
        for(int i=2;i<lists.size();i++){
            head=mergeTwoLists(head,lists[i]);
        }
        return head;
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode*run=new ListNode(0,nullptr);
        ListNode*temp=run;
        while(list1!=nullptr && list2!=nullptr){
            if(list1->val<list2->val) {
                temp->next=list1;
                list1=list1->next;
            }
            else {
                temp->next=list2;
                list2=list2->next;
            }
            temp=temp->next;
        }
        while(list1!=nullptr){
            temp->next=list1;
            list1=list1->next;
            temp=temp->next;
        }
        while(list2!=nullptr){
            temp->next=list2;
            list2=list2->next;
            temp=temp->next;
        }
        return run->next;
    }
};