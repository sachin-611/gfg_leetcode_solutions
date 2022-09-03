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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>res;
        if(root==nullptr)
            return res;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        while(q.empty()==false)
        {
            auto tops=q.front();
            q.pop();
            if(res.size()==tops.second)
                res.push_back({tops.first->val});
            else
                res[tops.second].push_back(tops.first->val);
            if(tops.first->left)
                q.push({tops.first->left,tops.second+1});
            if(tops.first->right)
                q.push({tops.first->right,tops.second+1});
        }
        return res;
    }
};