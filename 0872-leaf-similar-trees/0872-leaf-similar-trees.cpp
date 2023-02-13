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
    queue<int>q;
    bool dfs(TreeNode*root,int val=1){
        if(root==nullptr)
            return true;
        int v1=dfs(root->left,val);
        if(v1==false)
            return false;
        v1=dfs(root->right,val);
        if(v1==false)
            return false;
        if(!root->left and !root->right){
            if(val==1)q.push(root->val);
            else {
                if(q.empty() || q.front()!=root->val){
                    return false;
                }
                q.pop();
            };
        }
        return true;
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        dfs(root1);
        return dfs(root2,2) &&  q.empty();
    }
};