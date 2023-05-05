//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
}; 

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


// } Driver Code Ends
//User function Template for C++

class Solution{
    int res;
    void solve(Node*root, int &k,unordered_set<int>&oks){
        unordered_set<int>l,r;
        if(root->left)
            solve(root->left,k,l);
        if(root->right)
            solve(root->right,k,r);
        oks.insert(root->data);
        if(root->left and l.size()<=k)
            res++;
        if(root->right and r.size()<=k)
            res++;
        for(auto &i:l){
            oks.insert(i);
            if(oks.size()>k)
            return;
        }
        for(auto &j:r){
            oks.insert(j);
            if(oks.size()>k)
            return;
        }
    }
    /*
    
                    11 
           8                 10 
        11       12        7      7 
      9   10   N   13
    
    */
public:
    int goodSubtrees(Node *root,int k){
        // Code here
        if(!root)
            return 0;
        res=0;
        unordered_set<int>t;
        solve(root,k,t);
        if(t.size()<=k)res++;
        return res;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        if(i==0){
            string s;
            getline(cin,s);
        }
        string str;
        getline(cin,str);
        int k;
        cin>>k;
        string newline;
        getline(cin,newline);
        Node* root = buildTree(str);
        Solution ob;
        cout<<ob.goodSubtrees(root,k)<<endl;
    }
    return 0;
}
// } Driver Code Ends