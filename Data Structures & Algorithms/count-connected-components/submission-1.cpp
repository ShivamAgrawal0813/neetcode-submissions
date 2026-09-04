class Solution {
public:
    void dfs(int i, vector<vector<int>>& adj, vector<bool>& vis){
        
        for(auto ele:adj[i]){
            if(vis[ele])continue;
            vis[ele] =true;
            dfs(ele,adj,vis);
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<bool> vis(n,false);

        int comps = 0;

        for(int i=0;i<n;i++){
            
            if(vis[i])continue;

            vis[i] = true;
            dfs(i,adj,vis);
            comps++;
        }

        return comps;
    }
};
