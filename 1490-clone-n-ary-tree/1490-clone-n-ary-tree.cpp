/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
   Node* cloneTree(Node* r) {
    if (r == nullptr)
        return nullptr;
    auto new_r = new Node(r->val);
    for (auto child: r->children)
        new_r->children.push_back(cloneTree(child));
    return new_r;
}
};