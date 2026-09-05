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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 0) {
            return nullptr;
        }
        TreeNode* root = new TreeNode(preorder[0]);

        vector<int> inorder_right, preorder_right;
        vector<int> inorder_left, preorder_left;
        vector<int> *curr = &inorder_left;
        for(int i = 0; i < inorder.size(); i++) {
            if(inorder[i] == root->val) {
                curr = &inorder_right;
                continue;
            }
            curr->push_back(inorder[i]);
        }

        curr = &preorder_left;
        for(auto x:preorder) {
            if(curr->size() == inorder_left.size())
                curr = &preorder_right;
            if(x == root->val) continue;
            curr->push_back(x);
        }

        root->left = buildTree(preorder_left, inorder_left);
        root->right = buildTree(preorder_right, inorder_right);

        return root;
    }
};
