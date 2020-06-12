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
    int maxDepth(TreeNode* root) {
        return maxDepthAux(root, 0);
    }
    int maxDepthAux(TreeNode* root, int depth)
    {
        if (root == nullptr)
            return depth;
        else
            return max(maxDepthAux(root->left, depth+1), maxDepthAux(root->right, depth+1));
    }
};
