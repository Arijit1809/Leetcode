/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode* node;

node removeNthFromEnd(struct ListNode* head, int n){
    if(head == NULL) return NULL;
    node fast = head;
    node slow = head;
    //move fast pointer by n positions
    for(int i = 0; i < n; i++){
        fast = fast->next;
    }
    if(fast == NULL){
        node temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    while(fast->next!=NULL){
        slow=slow->next;
        fast=fast->next;
    }
    node temp = slow->next;
    slow->next = slow->next->next;
    free(temp);
    return head;
}