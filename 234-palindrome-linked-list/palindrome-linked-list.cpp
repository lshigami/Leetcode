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
    bool isPalindrome(ListNode* head) {
        if(head==nullptr) return true;
        if(head->next==nullptr) return true;
        int sz=0;
        ListNode*temp=head;
        while(temp){
            sz++;
            temp=temp->next;
        }
        stack<int>st;
        temp=head;
        for(int i=1;i<=sz;i++){
            if(sz%2!=0) {
                if(i==sz/2+1) {
                    temp=temp->next;
                    continue;
                }
            }
            if(i<=sz/2){
                st.push(temp->val);
                temp=temp->next;
            }
            else{
                if(temp->val!=st.top()) return false;
                st.pop();
                temp=temp->next;
            }
        }
        return true;
    }
};