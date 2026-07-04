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
    bool answer = true;
    int treeHeight(TreeNode* root) {
        int left = 0, right = 0;
        if(root == nullptr) return 0;
        if(root->left) {
            left = treeHeight(root->left);    
        }
        if(root->right) {
            right = treeHeight(root->right);
        }
        if(abs(right-left) > 1) answer = false;
        return 1 + max(left, right);
    }
    bool isBalanced(TreeNode* root) {
        treeHeight(root);
        return answer;
    }
};
