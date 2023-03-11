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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_set<int>ok;
        unordered_map<int,TreeNode*>m;
        TreeNode* par,*child;
        for(vector<int>&i:descriptions){
            if(!m.count(i[0])){
                par=new TreeNode(i[0]);
                m[i[0]]=par;
            }else{
                par=m[i[0]];
            }
            if(!m.count(i[1])){
                child=new TreeNode(i[1]);   
                m[i[1]]=child;
            }else{
                child=m[i[1]];
            }
            if(i[2]){
                par->left=child;
            }else{
                par->right=child;
            }
            ok.insert(child->val);
        }
        for(vector<int>&i:descriptions){
            if(!ok.count(i[0])){
                return m[i[0]];
            }
        }
        return nullptr;
    }
};