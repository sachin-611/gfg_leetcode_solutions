/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        queue<pair<Node*,int>>q;
        q.push({root,0});
        vector<vector<int>>res;
        map<int,vector<int>>mp;
        while(!q.empty())
        {
            auto top=q.front();
            q.pop();
            if(top.first==nullptr)
                continue;
            mp[top.second].push_back(top.first->val);
            for(auto j:(top.first)->children)
                if(j)
                    q.push({j,top.second+1});
        }
        for(auto i:mp)
            res.push_back(i.second);
        return res;
    }
};