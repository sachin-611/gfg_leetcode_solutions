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
    int sumNumbers(TreeNode* root) {
        int res=0;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        while(!q.empty()){
            auto top=q.front();
            q.pop();
            top.second*=10;
            top.second+=top.first->val;
            if(top.first->left or top.first->right){
                if(top.first->left){
                    q.push({top.first->left,top.second});
                }
                if(top.first->right){
                    q.push({top.first->right,top.second});
                }
            }else{
                res+=top.second;
            }
        }
        return res;
    }
};