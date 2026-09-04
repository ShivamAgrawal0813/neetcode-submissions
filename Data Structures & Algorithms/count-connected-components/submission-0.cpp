class Solution {
public:
    void dfs(int i, vector<bool>& vis, vector<vector<int>>& adj, int& n){
        vis[i] = true;

        for(auto ele:adj[i]){
            if(!vis[ele]){
                dfs(ele,vis,adj,n);
            }
        }
        
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        int ans = 0;

        vector<vector<int>> adj(n);
        for(auto edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<bool> vis(n,false);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                ans++;
                dfs(i,vis,adj,n);
            }
        }

        return ans;
    }
};
