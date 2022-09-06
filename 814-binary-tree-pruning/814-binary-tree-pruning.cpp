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
    int traverse(TreeNode *root)
    {
        if(root==nullptr)
            return 0;
        int lc=traverse(root->left);
        int rc=traverse(root->right);
        if(lc==0)
            root->left=nullptr;
        if(rc==0)
            root->right=nullptr;
        return lc+rc+(root->val==1);
    }
    TreeNode* pruneTree(TreeNode* root) {
        TreeNode *dummy=new TreeNode(1);
        dummy->left=root;
        dummy->right=nullptr;
        traverse(dummy);
        return dummy->left;
    }
};