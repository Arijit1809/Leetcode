/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    if(head == NULL) return NULL;
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    //move fast pointer by n positions
    for(int i = 0; i < n; i++){
        fast = fast->next;
    }
    if(fast == NULL){
        struct ListNode* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    while(fast->next!=NULL){
        slow=slow->next;
        fast=fast->next;
    }
    struct ListNode* temp = slow->next;
    slow->next = slow->next->next;
    free(temp);
    return head;
}