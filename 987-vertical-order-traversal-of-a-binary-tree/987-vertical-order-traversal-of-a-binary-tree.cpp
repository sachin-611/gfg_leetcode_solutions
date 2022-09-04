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
    map<int,vector<pair<int,int>>>mp;
    void travel(TreeNode* root,int level,int cnt)
    {
        if(root==nullptr)
            return;
        mp[level].push_back({cnt,root->val});
        travel(root->left,level-1,cnt+1);
        travel(root->right,level+1,cnt+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        mp.clear();
        travel(root,0,0);
        vector<vector<int>>res;
        for(auto &val:mp)
        {
            sort(val.second.begin(),val.second.end());
            vector<int>te;
            for(auto &j:val.second)
                te.push_back(j.second);
            res.push_back(te);
        }
        return res;
    }
};