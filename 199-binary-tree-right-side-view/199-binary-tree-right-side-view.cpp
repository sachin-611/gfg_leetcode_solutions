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
    vector<int>mp(101,-1);
class Solution {
public:
    void travel(TreeNode* root,int height)
    {
        if(root==nullptr)
            return;
        mp[height]=root->val;
        travel(root->left,height+1);
        travel(root->right,height+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        for(int &i:mp)
            i=-1;
        travel(root,0);
        vector<int>ans;
        for(auto i:mp)
            if(i!=-1)
                ans.push_back(i);
        return ans;
    }
};