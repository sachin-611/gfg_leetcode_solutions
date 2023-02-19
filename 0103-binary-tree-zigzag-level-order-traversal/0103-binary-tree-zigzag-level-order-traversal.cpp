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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>order;
        if(!root)
            return order;
        queue<TreeNode*>q;
        q.push(root);
        int sz=q.size();
        while(!q.empty()){
            sz=q.size();
            vector<int>temp;
            for(int i=0;i<sz;i++){
                auto &front=q.front();
                temp.push_back(front->val);
                if(front->left){
                    q.push(front->left);
                }
                if(front->right){
                    q.push(front->right);
                }
                q.pop();
            }
            order.push_back(temp);
        }
        for(int i=0;i<order.size();i++){
            if(i%2==1){
                reverse(order[i].begin(),order[i].end());
            }
        }
        return order;
    }
};