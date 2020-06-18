class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        std::deque<TreeNode*> que;
        enque(root, que);
        int sum = 0;
        auto iter = que.rbegin();
        while (iter != que.rend())
        {
            auto current = (*iter)->val;
            (*iter)->val += sum;
            sum += current;
            ++iter;
        }
        return root;
    }
    void enque(TreeNode* node, std::deque<TreeNode*>& que)
    {
        if (node == nullptr) return;
        enque(node->left, que);
        que.push_back(node);
        enque(node->right, que);
    }
};
