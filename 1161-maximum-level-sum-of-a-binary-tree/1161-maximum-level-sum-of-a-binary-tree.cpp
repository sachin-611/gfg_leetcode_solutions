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
    int maxLevelSum(TreeNode* root) {
        int ans=-1;
        int total=INT_MIN;
        queue<TreeNode*>q;
        int level=0;
        q.push(root);
        while(q.empty()==false){
            level++;
            int n=q.size();
            int sm=0;
            for(int i=0;i<n;i++){
                auto fr=q.front();
                q.pop();
                sm+=fr->val;
                if(fr->left){
                    q.push(fr->left);
                }
                if(fr->right){
                    q.push(fr->right);
                }
            }
            
            if(total<sm){
                ans=level;
                total=sm;
            }
        }
        return ans;
    }
};