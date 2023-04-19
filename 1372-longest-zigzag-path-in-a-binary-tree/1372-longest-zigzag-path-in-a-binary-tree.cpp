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
    // unordered_map<TreeNode*,int>left,right;
    int res;
    int longestZigZag(TreeNode* root,int left=0,int right=0) {
        if(!root)
            return 0;
        if(!left && !right){
            res=0;
        }
        if(res<left)
            res=left;
        if(res<right)
            res=right;
        longestZigZag(root->left,right+1,0);
        longestZigZag(root->right,0,left+1);
        return res;
    }
};