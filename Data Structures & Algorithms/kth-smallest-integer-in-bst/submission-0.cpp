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
    int ans = -1;
    int findOrder(TreeNode *root, int k, int elementsSmallerThan) {
        if(root == nullptr) {
            return 0;
        }
        int leftTreeCount = findOrder(root->left, k, elementsSmallerThan);
        if(leftTreeCount+elementsSmallerThan+1 == k) {
            ans = root->val;
        }
        int rightTreeCount = findOrder(root->right, k, elementsSmallerThan + leftTreeCount + 1);
        return 1 + leftTreeCount + rightTreeCount;
    }
    int kthSmallest(TreeNode* root, int k) {
        findOrder(root, k, 0);
        return ans;
    }
};
