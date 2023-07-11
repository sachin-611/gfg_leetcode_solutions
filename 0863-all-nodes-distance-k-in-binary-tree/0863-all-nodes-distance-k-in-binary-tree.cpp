/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*,TreeNode*>m;
    void generate(TreeNode* par,TreeNode* cur){
        if(cur==nullptr)
            return;
        m[cur]=par;
        generate(cur,cur->left);
        generate(cur,cur->right);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        m.clear();
        generate(nullptr,root);
        TreeNode *temp=target;
        queue<TreeNode*>q;
        q.push(temp);
        int level=0;
        vector<int>res;
        unordered_set<TreeNode*>vis;
        while(q.empty()==false){
            int sz=q.size();
            while(sz--){
                if(level==k)
                    res.push_back(q.front()->val);
                vis.insert(q.front());
                if(m[q.front()] and vis.count(m[q.front()])==0){
                    
                    vis.insert(m[q.front()]);
                    q.push(m[q.front()]);
                }
                if(q.front()->left and vis.count(q.front()->left)==0){
                    
                    vis.insert(q.front()->left);
                    q.push(q.front()->left);
                }
                if(q.front()->right and vis.count(q.front()->right)==0){
                    
                    vis.insert(q.front()->right);
                    q.push(q.front()->right);
                }
                q.pop();
            }
            level++;
            if(level>k)
                break;
        }
        return res;
    }
};