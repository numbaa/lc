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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> vec;
        generate(vec, root, 0);
        return vector<vector<int>>{ vec.rbegin(), vec.rend() };
    }
    void generate(vector<vector<int>>& vec, TreeNode* root, int depth)
    {
        if (root == nullptr) return;
        if (vec.size() < depth + 1)
        {
            vec.push_back(vector<int>{root->val});
        }
        else
        {
            vec[depth].push_back(root->val);
        }
        generate(vec, root->left, depth+1);
        generate(vec, root->right, depth+1);
    }
};
