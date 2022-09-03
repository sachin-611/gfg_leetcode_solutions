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
    vector<double> averageOfLevels(TreeNode* root) {
        map<int,pair<long long,int>>a;
        queue<pair<TreeNode*,long long>>q;
        q.push({root,0});
        while(q.empty()==false)
        {
            auto tops=q.front();
            q.pop();
            a[tops.second].first+=tops.first->val;
            a[tops.second].second+=1;
            if(tops.first->left)
            {
                q.push({tops.first->left,tops.second+1});
            }
            if(tops.first->right)
            {
                q.push({tops.first->right,tops.second+1});
            }
        }
        vector<double>res;
        for(auto i:a)
        {
            res.push_back((double)i.second.first/i.second.second);
        }
        return res;
    }
};