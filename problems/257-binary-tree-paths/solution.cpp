#include <vector>
#include <string>
using namespace std;

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
    vector<string> binaryTreePaths(TreeNode* root) {
        if (root == nullptr) return {};
        return binaryTreePaths(root, "");
    }
    vector<string> binaryTreePaths(TreeNode* node, string prefix) {
        prefix = prefix.empty() ? prefix + std::to_string(node->val) : prefix + "->" + std::to_string(node->val);
        if (node->left == nullptr && node->right == nullptr)
        {
            return vector{prefix};
        }
        vector<string> left = node->left == nullptr ? vector<string>{} : std::move(binaryTreePaths(node->left, prefix));
        vector<string> right = node->right == nullptr ? vector<string>{} : std::move(binaryTreePaths(node->right, prefix));
        left.insert(left.end(), right.begin(), right.end());
        return left;
    }
};