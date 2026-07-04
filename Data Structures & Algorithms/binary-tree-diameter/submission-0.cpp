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
    int maxChildren = 0;
    int getMaxHeight(TreeNode* root) {
        int left = 0, right = 0;
        if(!root) return 0;
        if(root->left) left = getMaxHeight(root->left);
        if(root->right) right = getMaxHeight(root->right);
        maxChildren = max(maxChildren, left + right);
        return 1 + max(left, right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        getMaxHeight(root);
        return maxChildren;
    }
};
