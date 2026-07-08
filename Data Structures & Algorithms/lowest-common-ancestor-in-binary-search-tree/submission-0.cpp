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
    TreeNode* lcaNode;
    bool isFound(TreeNode* root, TreeNode* p) {
        if(!root) return false;
        if(root == p) { return true; }
        return isFound(root->right, p) || isFound(root->left, p);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root && isFound(root, p) && isFound(root, q)) {
            lcaNode = root;
            lowestCommonAncestor(root->left,p,q);
            lowestCommonAncestor(root->right,p,q);
        }
        return lcaNode;
    }
};
