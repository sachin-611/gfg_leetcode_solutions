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
    int res=0;
    int longestZigZag(TreeNode* root,int left=-1,int right=-1) {
        if(root==nullptr)
            return 0;
        if(left==-1 and right==-1){
            res=0;
            left=right=res;
            // cout<<" sad"<<endl;
        }
        res=max({res,left,right});
        if(root->left){
            longestZigZag(root->left,right+1,0);
        }
        if(root->right){
            longestZigZag(root->right,0,left+1);
        }
        return res;
    }
};