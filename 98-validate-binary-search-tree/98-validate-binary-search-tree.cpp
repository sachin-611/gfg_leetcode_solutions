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
    vector<int>re;
    void travel(TreeNode*root)
    {
        if(root)
        {
            travel(root->left);
            re.push_back(root->val);
            travel(root->right);
        }
    }
    bool isValidBST(TreeNode* root) {
        re.clear();
        travel(root);
        for(int i=1;i<re.size();i++)
        {
            if(re[i]<=re[i-1])
                return false;
        }
        return true;
    }
};