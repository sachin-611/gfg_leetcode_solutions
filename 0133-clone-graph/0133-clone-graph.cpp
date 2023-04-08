/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<int,Node*>vis;
    Node* temp(Node* node){
        if(node==nullptr){
            return nullptr;
        }
        if(vis.count(node->val)){
            return vis[node->val];
        }
        Node *res=new Node;
        res->val=node->val;
        vis[res->val]=res;
        for(auto i:node->neighbors){
            res->neighbors.push_back(temp(i));
        }
        return res;
    }
    Node* cloneGraph(Node* node) {
        vis.clear();
        return temp(node);
    }
};