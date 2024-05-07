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

    ListNode* doubleIt(ListNode* head) {
        stack<ListNode*>st;
        ListNode*temp=head;
        while(temp){
            st.push(temp);
            temp=temp->next;
        }
        int remain=0;
        while(!st.empty()){
            int value=st.top()->val*2 +remain;
            remain=0;
            remain+=value/10;
            value=value%10;
            st.top()->val=value;
            ListNode*here=st.top();
            st.pop();
            if(st.empty()){
                if(remain==0) return here;
                else {
                    return new ListNode(remain,here);
                }
            }
        }
        return head;
    }
};