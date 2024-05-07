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
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*>st1,st2;
        ListNode*temp=head;
        while(temp){
            st1.push(temp);
            temp=temp->next;
        }
        while(!st1.empty()){
            while(!st2.empty() && st2.top()->val>st1.top()->val) {
                st1.pop();
                if(!st1.empty()) st1.top()->next=st2.top();
                else return st2.top();
            }
            st2.push(st1.top());
            st1.pop();
        }
        return head;
    }
};