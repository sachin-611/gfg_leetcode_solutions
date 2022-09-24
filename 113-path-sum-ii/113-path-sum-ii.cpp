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
    vector<vector<int>>res;
    vector<int>temp;
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root==nullptr)
            return res;
        if(root->left==root->right and root->left==nullptr)
        {
            //root node
            if(targetSum==root->val)
            {
                temp.push_back(root->val);
                res.push_back(temp);
                temp.pop_back();
            }
            return res;
        }
        temp.push_back(root->val);
        pathSum(root->left,targetSum-root->val);
        pathSum(root->right,targetSum-root->val);
        temp.pop_back();
        return res;
    }
};