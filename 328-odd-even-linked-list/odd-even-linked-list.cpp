class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode*odd=head;
        ListNode*even=head->next;
        ListNode*headofeven=even;
        while(even && even->next){
            odd->next=even->next;
            odd=odd->next;
            even->next=odd->next;
            even=even->next;
        }
        odd->next=headofeven;
        return head;
    }
};
