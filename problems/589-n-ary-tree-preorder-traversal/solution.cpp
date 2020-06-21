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
    vector<int> preorder(Node* root) {
        std::vector<int> result;
        preorder(root, result);
        return result;
    }
    void preorder(Node* node, std::vector<int>& result)
    {
        if (node == nullptr) return;
        result.push_back(node->val);
        for (auto child : node->children)
        {
            preorder(child, result);
        }
    }
};
