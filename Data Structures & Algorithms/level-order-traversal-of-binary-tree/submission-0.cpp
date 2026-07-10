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
    int maxLevel = 0;
    vector<vector<int>> ans;
    void fill(TreeNode* root, int level = 0) {
        if(!root) return;
        maxLevel = max(level, maxLevel);
        if(maxLevel != ans.size() - 1) ans.push_back({root->val});
        else ans[level].push_back(root->val);
        fill(root->left, level+1);
        fill(root->right, level+1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        fill(root);
        return ans;
    }
};
