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
    int ans=0;
    void solve(TreeNode* root,int maxi,int mini){
        if(root==nullptr)
            return;
        ans=max({ans,abs(maxi-root->val),abs(root->val-mini)});
        solve(root->left,max(maxi,root->val),min(mini,root->val));
        solve(root->right,max(maxi,root->val),min(mini,root->val));
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        ans=0;
        solve(root, root->val, root->val);
        return ans; 
    }
};