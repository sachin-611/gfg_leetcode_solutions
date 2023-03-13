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
    bool issame(TreeNode*root1, TreeNode*root2){
        if(root1==nullptr || root2==nullptr){
            return root2==nullptr and root1==nullptr;
        }
        if(root1->val!=root2->val){
            return false;
        }
        bool oks=issame(root1->right,root2->left);
        if(!oks)return false;
        oks=issame(root1->left,root2->right);
        return oks;
    }
    bool isSymmetric(TreeNode* root) {
        if(!root)return true;
        return issame(root->left,root->right);
    }
};