#include <string>
#include <vector>
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


struct Level {
    double sum = 0;
    int count = 0;
};
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<Level> levels;
        averageOfLevels(root, levels, 0);
        vector<double> results;
        results.resize(levels.size());
        for (int i=0; i<levels.size(); i++) {
            results[i] = levels[i].sum / levels[i].count;
        }
        return results;
    }
    void averageOfLevels(TreeNode* node, vector<Level>& levels, int level) {
        if (node == nullptr) return;
        if (levels.size() < level + 1) {
            auto tmp = Level{static_cast<double>(node->val), 1};
            levels.push_back(tmp);
        } else {
            auto& ref = levels[level];
            ref.sum += node->val;
            ref.count += 1;
        }
        averageOfLevels(node->left, levels, level+1);
        averageOfLevels(node->right, levels, level+1);
    }
};

int main()
{
    Solution s;
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->left->left = new TreeNode(15);
    root->left->right = new TreeNode(7);
    auto results = s.averageOfLevels(root);
    for (auto avg : results)
        cout << avg << ", ";
    cout << endl;
    return 0;
}
