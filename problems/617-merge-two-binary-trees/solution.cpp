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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        
        if (t1 == nullptr && t2 != nullptr)
            return t2;
        else if (t1 != nullptr && t2 == nullptr)
            return t1;
        else if (t1 == nullptr && t2 == nullptr)
            return nullptr;
        TreeNode* t3 = t1;
        t3->val += t2->val;
        t3->left = mergeTrees(t1->left, t2->left);
        t3->right = mergeTrees(t1->right, t2->right);
        return t3;
    }
    
};
