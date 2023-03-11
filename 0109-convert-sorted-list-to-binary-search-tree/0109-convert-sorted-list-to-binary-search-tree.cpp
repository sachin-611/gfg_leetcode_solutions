/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        ok.clear();
        while(head){
            ok.push_back(head->val);
            head=head->next;
        }
        if(ok.empty())return nullptr;
        return solve(0,ok.size()-1);
    }
};