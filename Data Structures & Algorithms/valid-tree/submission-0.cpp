class Solution {
public:
    bool bfs(int i, vector<bool>& vis, vector<vector<int>>& adj){

        queue<pair<int,int>> q;
        q.push({i,-1});
        
        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            
            for(auto adjNode:adj[node]){
                // cout<<adjNode<<" "<<node<<" ";
                if(!vis[adjNode]){
                    vis[adjNode] = true;
                    q.push({adjNode,node});
                }else if(adjNode!=parent)return true;
            }
        }
        
        return false;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<bool> vis(n,false);
        int connComps = 0;

        for(int i=0;i<n;i++){
            if(!vis[i]){
                connComps++;
                if(connComps>1)return false;
                vis[i] =true;
                if(bfs(i,vis,adj))return false;
            }
        }
        return true;
    }
};
