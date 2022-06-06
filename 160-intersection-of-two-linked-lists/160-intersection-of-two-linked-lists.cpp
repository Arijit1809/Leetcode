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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *ans;
        while(headA){
            ans = traverse(headB,headA);
            if(ans) return ans;
            else headA = headA->next;
        } 
        return NULL;
    }
    
    ListNode *traverse(ListNode *node, ListNode *comp){
        if(!node) return NULL;
        if(node == comp) return node;
        else return traverse(node->next,comp);
    }
};