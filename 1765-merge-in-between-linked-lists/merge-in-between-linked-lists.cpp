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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode*head=list1;
        int counter=1;
        while(list1 && counter<a){
            head=head->next;
            counter+=1;
        }
        ListNode*fromb=head;
        for(int i=a;i<=b;i++){
            fromb=fromb->next;
        }
        head->next=list2;
        while(list2->next){
            list2=list2->next;
        }
        fromb=fromb->next;
        list2->next=fromb;
        return list1;
        
    }
};