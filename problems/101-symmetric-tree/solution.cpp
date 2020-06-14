#include <deque>
#include <iostream>

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
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return false;
        if (root->left == nullptr && root->right == nullptr) return true;
        if (root->left && root->right)
        {
            std::deque<TreeNode*> que;
            iterateLeft(root->left, que);
            return checkRight(root->right, que);
        }
        return false;
    }
    void iterateLeft(TreeNode* node, std::deque<TreeNode*>& que)
    {
        que.push_back(node);
        if (node == nullptr)
            return;
        iterateLeft(node->left, que);
        iterateLeft(node->right, que);
    }
    bool checkRight(TreeNode* node, std::deque<TreeNode*>& que)
    {
        if (node == nullptr && que.front() == nullptr)
        {
            que.pop_front();
            return true;
        }
        else if (node && !que.empty() && que.front() != nullptr && node->val == que.front()->val)
        {
            que.pop_front();
            return checkRight(node->right, que) && checkRight(node->left, que);
        }
        else
            return false;
    }
};

int main()
{
    TreeNode* root = new TreeNode{1};
    root->left = new TreeNode{2};
    root->left->left = new TreeNode{3};
    root->left->right = new TreeNode{4};
    root->right = new TreeNode{2};
    root->right->right = new TreeNode{3};
    //root->right->left = new TreeNode{5};
    Solution s;
    std::cout << std::boolalpha << s.isSymmetric(root) << std::endl;;
    return 0;
}

