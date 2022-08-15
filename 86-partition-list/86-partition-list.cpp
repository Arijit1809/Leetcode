class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        
        if(!head){
            return head;
        }
        
        ListNode* left = new ListNode (-1);
        ListNode* leftHead = left;
        ListNode* right = new ListNode (-1);
        ListNode* rightHead = right;
        
        while(head != NULL){
            if(head->val < x){
                left->next = head;
                left = left->next;
            } 
            else{
                right->next = head;
                right = right->next;
            }
            head = head->next;
        }

        left->next =  rightHead->next;
        right->next = NULL;
        
        return leftHead->next;
    }
};