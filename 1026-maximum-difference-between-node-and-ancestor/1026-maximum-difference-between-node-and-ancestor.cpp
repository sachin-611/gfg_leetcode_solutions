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
    int maxAncestorDiff(TreeNode* root) {
        return dfs(root, root->val, root->val);
    }

    int dfs(TreeNode* node, int minVal, int maxVal) {
        if (node == nullptr) {
            return maxVal - minVal;
        }

        minVal = min(minVal, node->val);
        maxVal = max(maxVal, node->val);

        int leftDiff = dfs(node->left, minVal, maxVal);
        int rightDiff = dfs(node->right, minVal, maxVal);

        return max(leftDiff, rightDiff);
    }
};