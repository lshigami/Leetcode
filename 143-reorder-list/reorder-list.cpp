class Solution {
private:
    ListNode* findMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* second = nullptr;
        ListNode* first = nullptr;
        ListNode* temp = head;
        while (head) {
            second = head->next;
            head->next = first;
            first = head;
            head = second;
        }
        return first;
    }

    void mergeLists(ListNode* first, ListNode* second) {
        ListNode* tmp;
        while (second->next != NULL) {
            tmp = first->next;
            first->next = second;
            first = tmp;
            tmp = second->next;
            second->next = first;
            second = tmp;
        }
    }

public:
    void reorderList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return;

        // Tìm điểm giữa của danh sách liên kết
        ListNode* middle = findMiddle(head);

        // Đảo ngược nửa sau của danh sách
        ListNode* secondHalf = reverseList(middle);

        // Trộn hai nửa danh sách
        mergeLists(head, secondHalf);
    }
};