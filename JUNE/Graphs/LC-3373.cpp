class Solution {
public:
    void Bfs(int start,vector<vector<int>>& adj,int &best2,
            vector<int>&vis,int slvl){
        fill(vis.begin(),vis.end(),0);
        queue<pair<int,int>>q;
        //level,node
        q.push({slvl,start});
        vis[start]=1;
        int even=0;
        while(!q.empty()){
            auto[level,node]=q.front();q.pop();
            if(level%2==0) even++;
            for(auto it:adj[node]){
                int adjNode=it;
                if(!vis[adjNode]){
                    vis[adjNode]=1;
                    q.push({level+1,adjNode});
                }     
            }
        }
                    best2=max(best2,even);
    }
    void Bfs2(int start,vector<vector<int>>& adj,
            vector<int>&vis,int slvl, vector<int>&oddOrEven){
        fill(vis.begin(),vis.end(),0);
        queue<pair<int,int>>q;
        //level,node
        q.push({slvl,start});
        vis[start]=1;
        while(!q.empty()){
            auto[level,node]=q.front();q.pop();
            if(level%2==0) oddOrEven[node]=1;
            for(auto it:adj[node]){
                int adjNode=it;
                if(!vis[adjNode]){
                    vis[adjNode]=1;
                    q.push({level+1,adjNode});
                }     
            }
        }
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int node1=0;
        int n=edges1.size()+1;int m=edges2.size()+1;
        vector<int>vis(max(edges1.size()+1,edges2.size()+1),0);
        vector<vector<int>>adj2(m);
        //adj2
        for(auto &edge:edges2){
            int u=edge[0];int v=edge[1];
            adj2[u].push_back(v);
            adj2[v].push_back(u);
        }
        vector<vector<int>>adj1(n);
        //adj1
        for(auto &edge:edges1){
            int u=edge[0];int v=edge[1];
            adj1[u].push_back(v);
            adj1[v].push_back(u);
        }
        //Tree-2
        int best2=0;
            Bfs(0,adj2,best2,vis,1);
            Bfs(adj2[0][0],adj2,best2,vis,1);
        //Tree-1
        int besteven1=0;
        int bestodd1=0;
        vector<int>ans(n);
            Bfs(0,adj1,besteven1,vis,0);
            Bfs(adj1[0][0],adj1,bestodd1,vis,0);
            vector<int>oddOrEven(max(edges1.size()+1,edges2.size()+1),0);
            Bfs2(0,adj1,vis,0, oddOrEven);
            cout<<best2<<" "<<besteven1<<" "<<bestodd1;
        for(int i=0;i<n;i++){
            (oddOrEven[i])?ans[i]=besteven1+best2:ans[i]=bestodd1+best2;
        }
        return ans;
        
    }
};