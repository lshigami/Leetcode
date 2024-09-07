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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_map<int,int>m;
        for(auto x:nums){
            m[x]=1;
        }
        ListNode*temp=head;
        ListNode*dummy=new ListNode(0,head);
        ListNode*prev=dummy;
        while(temp){
            if(m[temp->val]){
                prev->next=temp->next;
                temp=temp->next;
            }
            else{
                prev=prev->next;
                temp=temp->next;
            }
        }
        return dummy->next;
    }
};