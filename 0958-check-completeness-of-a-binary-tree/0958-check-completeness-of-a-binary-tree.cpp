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
    bool isCompleteTree(TreeNode* root) {
        if(!root){
            return true;
        }
        queue<TreeNode*>q;
        q.push(root);
            int cnt=0;
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                auto temp=q.front();
                q.pop();
                if(temp->left){
                    if(cnt){
                        return false;
                    }
                    q.push(temp->left);
                }else{
                    cnt=1;
                }
                // cout<<cnt<<" ";
                if(temp->right){
                    if(cnt){
                        return false;
                    }
                    q.push(temp->right);
                }else{
                    cnt=1;
                }
                // cout<<cnt<<" "<<temp->val<<endl;
            }
        }
        return true;
    }
};