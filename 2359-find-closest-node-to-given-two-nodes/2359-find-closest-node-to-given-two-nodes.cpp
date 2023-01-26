class Solution {
    vector<vector<int>>pos;
    vector<vector<int>>m;
    void bfs(int &node,int i,int &n)
    {
        queue<pair<int,int>>q;
        q.push({node,0});
        vector<int>vis(n);
        while(q.empty()==false)
        {
            auto tops=q.front();
            q.pop();
            vis[tops.first]=1;
            pos[tops.first][i]=tops.second;
                for(auto &child:m[tops.first])
                {
                    if(vis[(child)]==0)
                    {
                        q.push({child,tops.second+1});
                        vis[(child)]=1;
                    }
                }
        }
    }
public:
    
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n=edges.size();
        m.resize(n);
        pos.resize(n,vector<int>(2,-1));
        for(int i=0;i<n;i++)
        {
            if(edges[i]==-1)
                continue;
            m[i].push_back(edges[i]);
        }
        bfs(node1,0,n);
        bfs(node2,1,n);
        int res=-1;
        for(int i=0;i<n;i++)
        {
            if(pos[i][0]!=-1 and pos[i][1]!=-1)
            {
                    pos[i][0]=max(pos[i][0],pos[i][1]);
                if(res==-1)
                {
                    res=i;
                }
                else if(pos[res][0]>pos[i][0])
                    res=i;
            }
        }
        return res;
    }
};