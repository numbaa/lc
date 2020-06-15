/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == nullptr) return false;
        if (root->val == sum && root->left == nullptr && root->right == nullptr) return true;
        return hasPathSum(root->left, root->val, sum) || hasPathSum(root->right, root->val, sum);
    }
    bool hasPathSum(TreeNode* node, int prevSum, int target)
    {
        if (node == nullptr) return false;
        if (node->val + prevSum == target && node->left == nullptr && node->right == nullptr) return true;
        return hasPathSum(node->left, node->val + prevSum, target) || hasPathSum(node->right, node->val + prevSum, target);
    }
};
