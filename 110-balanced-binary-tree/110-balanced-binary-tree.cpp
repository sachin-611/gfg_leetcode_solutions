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
    bool isBalanced(TreeNode* root) {
        if(root==nullptr)
            return true;
        int h1=height(root->left);
        int h2=height(root->right);
        return abs(h1-h2)<=1 and isBalanced(root->left) and isBalanced(root->right);
    }
    int height(TreeNode *root)
    {
        if(root==nullptr)
            return 0;
        int l=height(root->left);
        int r=height(root->right);
        return max(l,r)+1;
    }
};