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
    string tree2str(TreeNode* t) {
        std::stringstream ss;
        tree2str(t, ss);
        return ss.str();
    }
    void tree2str(TreeNode* t, std::stringstream& ss)
    {
        if (t == nullptr) return;
        ss << t->val;
        if (t->left != nullptr)
        {
            ss << '(';
            tree2str(t->left, ss);
            ss << ')';
        }
        else if (t->right != nullptr)
            ss << "()";
        if (t->right != nullptr)
        {
             ss << '(';
            tree2str(t->right, ss);
            ss << ')';
        }
        
       
    }
    
};
