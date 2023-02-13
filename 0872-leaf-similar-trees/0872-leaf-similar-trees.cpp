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
    vector<int>tree1,tree2;
    void dfs(TreeNode*root,int val=1){
        if(root==nullptr)
            return;
        dfs(root->left,val);
        dfs(root->right,val);
        if(!root->left and !root->right){
            if(val==1)tree1.push_back(root->val);
            else tree2.push_back(root->val);
        }
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        dfs(root1);
        dfs(root2,2);
        return tree1==tree2;
    }
};