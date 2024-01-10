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
    map<TreeNode*,int>m;
    int travel(TreeNode *root,int start, int time){
        if(root==nullptr){
            return -1;
        }
        if(root->val==start){
            m[root]=time=0;
        }
        if(time==-1){
            m[root]=time;
            travel(root->left,start,time);
            if(root->left and m[root->left]!=-1){
                time=m[root]=m[root->left]+1;
                travel(root->right,start,time+1);
                return -1;
            }
            travel(root->right,start,time);
            if(root->right and m[root->right]!=-1){
                time=m[root]=m[root->right]+1;
            }
            travel(root->left,start,time+1);
        }else{
            m[root]=time;
            travel(root->left,start,time+1);
            travel(root->right,start,time+1);
        }
        return -1;
    }
    int amountOfTime(TreeNode* root, int start) {
        travel(root,start,-1);
        int res=0;
        for(auto &i:m){
            res=max(res,i.second);
        }
        return res;
    }
};