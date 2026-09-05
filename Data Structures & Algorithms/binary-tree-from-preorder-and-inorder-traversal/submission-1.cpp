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
        return build(preorder, inorder);
    }

    TreeNode* build(span<int> preorder, span<int> inorder) {
        if (preorder.empty()) return nullptr;

        TreeNode* root = new TreeNode(preorder[0]);

        int left_size = 0;
        while (inorder[left_size] != root->val) ++left_size;

        root->left  = build(preorder.subspan(1, left_size), inorder.subspan(0, left_size));
        root->right = build(preorder.subspan(1 + left_size), inorder.subspan(left_size + 1));

        return root;
    }
};
