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
        int carry=0;
        ListNode*a=l1;
        ListNode*b=l2;
        ListNode*ans=new ListNode();
        ListNode*res= ans;
        
        while(a!=nullptr || b!=nullptr || carry){
            int sum=(a!=nullptr ? a->val : 0)+(b!=nullptr ? b->val : 0)+carry;
            carry=0;
            ListNode*newNode=new ListNode(sum%10);
            carry +=sum/10;
            res->next=newNode;
            res=res->next;
            if(a!=nullptr) a=a->next;
            if(b!=nullptr) b=b->next;
        }
        return ans->next;
    }
};