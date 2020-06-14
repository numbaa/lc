class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root== nullptr) return 0;
        int32_t min_depth = std::numeric_limits<int32_t>::max();
        int32_t depth = 1;
        return minDepth(root, min_depth, depth);
    }
    int minDepth(TreeNode* root, int32_t& min_depth, int32_t depth)
    {
        if (min_depth < depth) return min_depth;
        if (root->left == nullptr && root->right == nullptr)
        {
            if (depth < min_depth)
            {
                min_depth = depth;
            }
            return min_depth;
        }
        int32_t left_min = root->left == nullptr ? std::numeric_limits<int32_t>::max() : minDepth(root->left, min_depth, depth+1);
        int32_t right_min = root->right == nullptr ? std::numeric_limits<int32_t>::max() : minDepth(root->right, min_depth, depth+1);
        return std::min(left_min, right_min);
    }
};
