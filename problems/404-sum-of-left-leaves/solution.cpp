
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == nullptr) return 0;
        return
            root->left == nullptr ? 0 : sumOfLeftLeaves(root->left, true)
            +
            root->right == nullptr ? 0 : sumOfLeftLeaves(root->right, false);
    }
    int sumOfLeftLeaves(TreeNode* node, bool isLeft) {
        if (node->left == nullptr && node->right == nullptr && isLeft)
            return node->val;
        int left = node->left == nullptr ? 0 : sumOfLeftLeaves(node->left, true);
        int right = node->right == nullptr ? 0 : sumOfLeftLeaves(node->right, false);
        return left + right;
    }
};
