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
    TreeNode* last=nullptr;
    int diff=1000000;
    int minDiffInBST(TreeNode* root) {
        if(root==nullptr)
            return diff;
        minDiffInBST(root->left);
        if(last)
            diff=min(diff,root->val-last->val);
        last=root;
        minDiffInBST(root->right);
        return diff;
    }
};