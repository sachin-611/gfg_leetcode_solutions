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
    int minDiffInBST(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        vector<int>data;
        while(q.empty()==false){
            auto node=q.front();
            data.push_back(node->val);
            q.pop();
            if(node->left!=nullptr){
                q.push(node->left);
            }
            if(node->right!=nullptr){
                q.push(node->right);
            }
        }
        sort(data.begin(),data.end());
        int n=data.size(),res=1e9;
        for(int i=1;i<n;i++){
            res=min(res,data[i]-data[i-1]);
        }
        return res;
    }
};