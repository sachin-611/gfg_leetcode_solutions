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
        map<int,TreeNode*>m;
        for(vector<int>&i:descriptions){
            if(!m.count(i[0])){
                m[i[0]]=new TreeNode(i[0]);
            }
            if(!m.count(i[1])){
                m[i[1]]=new TreeNode(i[1]);   
            }
            if(i[2]){
                m[i[0]]->left=m[i[1]];
            }else{
                m[i[0]]->right=m[i[1]];
            }
            ok.insert(i[1]);
        }
        for(vector<int>&i:descriptions){
            if(!ok.count(i[0])){
                return m[i[0]];
            }
        }
        return nullptr;
    }
};