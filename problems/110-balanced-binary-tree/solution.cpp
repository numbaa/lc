#include <iostream>
#include <limits>
#include <tuple>

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
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) return true;
        int height = 1;
        auto [left_balanced, left_height] = getBalancedHeight(root->left, height);
        auto [right_balanced, right_height] = getBalancedHeight(root->right, height);
        if (!left_balanced || !right_balanced)
            return false;
        return std::abs(left_height - right_height) <= 1;
    }
    std::tuple<bool, int> getBalancedHeight(TreeNode* root, int height)
    {
        if (root == nullptr)
            return std::make_tuple(true, height);
        auto [left_balanced, left_height] = getBalancedHeight(root->left, height+1);
        auto [right_balanced, right_height] = getBalancedHeight(root->right, height+1);
        if (!left_balanced || !right_balanced)
            return std::make_tuple(false, 0);
        return std::make_tuple(std::abs(left_height - right_height) <= 1, std::max(left_height, right_height));
    }
};

