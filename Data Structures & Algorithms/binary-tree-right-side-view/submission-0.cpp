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
    vector<int> sol;
    void solve(TreeNode* root, int level = 0) {
        if(!root) return;
        if(level == sol.size()) sol.push_back(root->val);
        else sol[level] = root->val;
        solve(root->left, level+1);
        solve(root->right, level+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        solve(root);
        return sol;
    }
};
