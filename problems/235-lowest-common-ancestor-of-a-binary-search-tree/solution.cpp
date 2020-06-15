/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int small = std::min(p->val, q->val);
        int big = std::max(p->val, q->val);
        return lowest(root, small, big);
    }
    TreeNode* lowest(TreeNode* node, int small, int big)
    {
        if (node->val == small || node->val == big)
            return node;
        if (node->val > small && node->val < big)
            return node;
        if (node->val > big)
            return lowest(node->left, small, big);
        if (node->val < small)
            return lowest(node->right, small, big);
        return nullptr;
    }
};
