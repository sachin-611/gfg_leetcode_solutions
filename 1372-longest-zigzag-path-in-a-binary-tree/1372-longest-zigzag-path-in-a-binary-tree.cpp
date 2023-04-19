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
    int res;
    unordered_map<TreeNode*,int>left,right;
    int solve(TreeNode* root){
        if(root==nullptr)
            return 0;
        auto &lef=left[root];
        auto &righ=right[root];
        res=max(res,solve(root->left));
        res=max(solve(root->right),res);
        if(root->left){
            lef=right[root->left]+1;
        }
        if(root->right){
            righ=left[root->right]+1;
        }
        return res=max({res,lef,righ});
    }
    int longestZigZag(TreeNode* root) {
        res=0;
        left.clear();
        right.clear();
        solve(root);
        return res;
    }
};