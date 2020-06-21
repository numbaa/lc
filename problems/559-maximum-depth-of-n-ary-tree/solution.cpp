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
    int maxDepth(Node* root) {
        return maxDepth(root, 0);
    }
    int maxDepth(Node* node, int depth)
    {
        if (node == nullptr) return depth;
        int max_depth = depth + 1;
        for (auto child : node->children)
        {
            int tmp = maxDepth(child, depth+1);
            if (tmp > max_depth)
                max_depth = tmp;
        }
        return max_depth;
    }
};
