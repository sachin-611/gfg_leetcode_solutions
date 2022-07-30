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
        map<int,int>mp;
    void travel(TreeNode* root,int height)
    {
        if(root==nullptr)
            return;
        mp[height]=root->val;
        travel(root->left,height+1);
        travel(root->right,height+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        mp.clear();
        travel(root,0);
        vector<int>ans;
        
        for(auto i:mp)
            ans.push_back(i.second);
        return ans;
    }
};