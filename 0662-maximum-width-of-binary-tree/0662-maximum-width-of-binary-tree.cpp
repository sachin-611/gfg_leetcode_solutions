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
    unsigned long long widthOfBinaryTree(TreeNode* root) {
        unsigned long long res=0;
        queue<pair<TreeNode*,unsigned long long>>q;
        q.push({root,0});
        int cnt=0;
        while(!q.empty()){
            int sz=q.size();
            unsigned long long sec=-1,fir=-1;
            while(sz--){
                auto temp=q.front();
                q.pop();
                if(fir==-1){
                    fir=temp.second;
                }
                sec=temp.second;
                if(temp.first->left)
                q.push({temp.first->left,temp.second*2});
                if(temp.first->right)
                q.push({temp.first->right,temp.second*2+1});
            }
            res=max(res,(sec-fir+1));
        }
        return res;
    }
};