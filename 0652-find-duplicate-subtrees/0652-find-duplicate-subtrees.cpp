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
    vector<TreeNode*>temp;
    unordered_map<string,TreeNode*>mp;
    unordered_set<string>used;
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        temp.clear();
        mp.clear();
        used.clear();
        cal(root);
        return temp;
    }
    string cal(TreeNode* root){
        if(root==nullptr){
            return "";
        }
        string left=cal(root->left);
        string right=cal(root->right);
        string cur="("+left+ ")"+to_string(root->val)+"("+right+")";
        if(mp.count(cur) and !used.count(cur)){
            temp.push_back(root);
            used.insert(cur);
        }
        mp[cur]=root;
        return cur;
    }
};