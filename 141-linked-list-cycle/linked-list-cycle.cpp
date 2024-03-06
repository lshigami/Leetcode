/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==nullptr) return false;
        for(int i=0;i<=100000;i++){
            if(head && head->next==nullptr) return false;
            head=head->next;
        }
        return true;
    }
};