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
    bool validateBST(TreeNode* root, int max, int min) {
        if(!root) return true;
        if(root->left && (root->left->val >= root->val || root->left->val >= max || root->left->val <= min)) {
            return false;
        }
        if(root->right && (root->right->val <= root->val || root->right->val >= max || root->right->val <= min)) {
            return false;
        }
        bool leftValid = root->left ? validateBST(root->left, root->val, min) : true;
        bool rightValid = root->right ? validateBST(root->right, max, root->val) : true;
        return leftValid && rightValid;
    }

    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        return validateBST(root, INT32_MAX, INT32_MIN);
    }
};
