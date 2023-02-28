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
    vector<TreeNode *> res;
    unordered_map<string,int> myMap;
public:
    string solve(TreeNode *root){
        if(!root)
        return "#";

        string left = solve(root->left);
        string right = solve(root->right);

        string temp = to_string(root->val) + "," + left + right;
        myMap[temp]++;
        if(myMap[temp] == 2)
        res.push_back(root);

        return temp;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        solve(root);
        return res;
    }
};