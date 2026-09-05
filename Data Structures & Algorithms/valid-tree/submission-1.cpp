class Solution {
public:
    bool dfs(int i, int parent, vector<vector<int>>& adj, vector<bool>& vis){
        vis[i] = true;

        for(auto j:adj[i]){
            if(!vis[j]){
                // cout<<j<<" ";
                dfs(j,i,adj,vis);
                
            }
            else {
                if(j!=parent){
                    cout<<j<<" ";
                    return false;
                }
            }
        }

        return true;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        int comps = 0;
        vector<bool> vis(n,0);

        vector<vector<int>> adj(n);

        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        for(int i=0;i<n;i++){
            if(vis[i]==true)continue;
            comps++;
            if(comps>1)return false;
            if(!dfs(i,-1,adj,vis))return false;
            
        }

        return true;
    }
};
