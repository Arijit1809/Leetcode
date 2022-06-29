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
    ListNode* plusOne(ListNode* head) {
        int hasCarry = carryOver(head);
        if(hasCarry){
            ListNode* newHead = new ListNode(1,NULL);
            newHead->next = head;
            return newHead;
        }else{
            return head;
        }
    }
    int carryOver(ListNode* node){
        if(node->next==NULL){
            node->val+=1;
            int hasCarry = node->val/10;
            node->val = node->val%10;
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