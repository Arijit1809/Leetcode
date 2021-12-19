/**
 * // This is the ImmutableListNode's API interface.
 * // You should not implement it, or speculate about its implementation.
 * class ImmutableListNode {
 * public:
 *    void printValue(); // print the value of the node.
 *    ImmutableListNode* getNext(); // return the next node.
 * };
 */

class Solution {
public:
    void printLinkedListInReverse(ImmutableListNode* head) {
        stack<ImmutableListNode*> list;
        ImmutableListNode* node = head;
        list.push(head);
        while(node->getNext()){
            ImmutableListNode* nextNode = node->getNext();
            list.push(nextNode);
            node=nextNode;
        }
        while(!list.empty()){
            ImmutableListNode* currNode = list.top();
            list.pop();
            currNode->printValue();
        }
    }
};