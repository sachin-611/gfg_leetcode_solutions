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
    string tree2str(TreeNode* root) {
        if(root==nullptr)
            return "";
        string left=tree2str(root->left);
        string right=tree2str(root->right);
        string res=to_string(root->val);
        if((left.empty()==true && right.empty()==false)||(left.empty()==false && right.empty()==false))
        {
            res=res+"("+left+")";
            res=res+"("+right+")";
        }    
        else if(left.empty()==false)
        {
            res=res+"("+left+")";
        }
            
        return res;
    }
};