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
    int minDepth(TreeNode* root) {
        if(root==nullptr)
            return 0;
        queue<pair<TreeNode*,int>>q;
        q.push({root,1});
        while(q.empty()==false)
        {
            auto top=q.front();
            q.pop();
            if(top.first->left==nullptr and top.first->right==nullptr)
                return top.second;
            if(top.first->left)
                q.push({top.first->left,top.second+1});
            if(top.first->right)
                q.push({top.first->right,top.second+1});
        }
        return 0;
    }
};