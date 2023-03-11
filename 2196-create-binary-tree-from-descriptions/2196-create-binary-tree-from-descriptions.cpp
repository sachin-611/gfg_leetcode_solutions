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
        int a,b,c;
        for(vector<int>&i:descriptions){
            a=i[0],b=i[1],c=i[2];
            if(!m.count(a)){
                par=new TreeNode(a);
                m[a]=par;
            }else{
                par=m[a];
            }
            if(!m.count(b)){
                child=new TreeNode(b);   
                m[b]=child;
            }else{
                child=m[b];
            }
            if(c){
                par->left=child;
            }else{
                par->right=child;
            }
            ok.insert(b);
        }
        for(vector<int>&i:descriptions){
            if(!ok.count(i[0])){
                return m[i[0]];
            }
        }
        return nullptr;
    }
};