class Solution {
public:
    ListNode* plusOne(ListNode* head) {
        int hasCarry = carryOver(head);
        if(hasCarry){
            ListNode* newHead = new ListNode(1,head);
            return newHead;
        }else{
            return head;
        }
    }
    int carryOver(ListNode* node){
        if(node->next==NULL){
            int hasCarry = (node->val+1)/10;
            node->val = (node->val+1)%10;
            return hasCarry;
        }
        int valueOfThisNode = node->val;
        int isCarryOver = carryOver(node->next);
        if(isCarryOver==1){
            node->val+=1;
        }
        int hasCarry = node->val/10;
        node->val = node->val%10;
        return hasCarry;
    }
};