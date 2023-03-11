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
    vector<int>ok;
    TreeNode* solve(int l,int r){
        if(l>r){
            return nullptr;
        }
        if(l==r){
            return new TreeNode(ok[l]);
        }
        int mid=(r-l)/2+l;
        TreeNode* cur=new TreeNode(ok[mid]);
        cur->left=solve(l,mid-1);
        cur->right=solve(mid+1,r);
        return cur;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        ok=nums;
        return solve(0,nums.size()-1);
    }
};