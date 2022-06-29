class Solution {
public:
    ListNode* plusOne(ListNode* head) {
        // sentinel head
        ListNode* sentinel = new ListNode(0);
        sentinel->next = head;
        ListNode* notNine = sentinel;

        // find the rightmost not-nine digit
        while (head != nullptr) {
            if (head->val != 9) notNine = head;
            head = head->next;
        }
        // increase this rightmost not-nine digit by 1
        notNine->val++;
        notNine = notNine->next;
        // set all the following nines to zeros
        while (notNine != nullptr) {
            notNine->val = 0;
            notNine = notNine->next;
        }

        delete notNine;
        return sentinel->val != 0 ? sentinel : sentinel->next;
    }
};