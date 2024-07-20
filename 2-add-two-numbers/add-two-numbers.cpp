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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* n1=l1;
        ListNode* n2=l2;
        ListNode* l3=new ListNode();
        ListNode* n3=l3;
        int carry=0;
        while(n1 || n2 || carry ){
            int a = (n1) ? n1->val : 0;
            int b = (n2) ? n2->val : 0;
            int sum= (a+b+carry)%10;
            ListNode*newNode = new ListNode(sum);
            n3->next=newNode;
            n3=n3->next;
            carry=(a+b+carry)/10;
            if(n1) n1=n1->next;
            if(n2) n2=n2->next;
        }
        l3=l3->next;
        return l3;
    }
};