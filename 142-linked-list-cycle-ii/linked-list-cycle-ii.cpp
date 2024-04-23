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
    ListNode *detectCycle(ListNode *head) {
        ListNode*slow=head;
        ListNode*fast=head;
        bool isCycle=false;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
            if(fast && fast==slow) {
                isCycle=true;
                break;
            }

        }
        if(!isCycle) return nullptr;
        slow = head;
        while (fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
    }
};