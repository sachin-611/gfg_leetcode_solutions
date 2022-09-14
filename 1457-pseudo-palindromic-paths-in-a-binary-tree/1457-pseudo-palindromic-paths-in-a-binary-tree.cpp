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
    map<int,int>m;
    int pseudoPalindromicPaths (TreeNode* root,int cnt=0) {
        if(root==nullptr)
            return 0;
        if(m[root->val]%2==0)
            cnt++;
        else
            cnt--;
        m[root->val]++;
        int left=0;
        if(root->left)
        {
            left=pseudoPalindromicPaths(root->left,cnt);
        }
        int right=0;
        if(root->right)
        {
            right=pseudoPalindromicPaths(root->right,cnt);
        }
        if(root->left==nullptr and root->right==nullptr and cnt<=1)
            left++;
        m[root->val]--;
        return left+right;
    }
};