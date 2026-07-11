class Solution {
public:

    void dfs(int i, vector<bool>& vis, vector<vector<int>>& adj)
    {
        if(vis[i])
        {
            return;
        }
        vis[i] = true;
        for(int it : adj[i])
        dfs(it, vis, adj);
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for( auto it: edges)
        {
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> vis(n,false);
        int count = 0;
        for(int i = 0; i<n; i++)
        {
            if(!vis[i])
            {
                count++;
                dfs(i, vis, adj);
            }
        }
        return count;
    }
};
