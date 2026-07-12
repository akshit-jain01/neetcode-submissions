class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto it:times)
        {
            int u = it[0];
            int v = it[1];
            int t = it[2];

            adj[u].push_back({v, t});
        }
        vector<int> dist(n+1, INT_MAX);
        pq.push({0, k});   // pq stores the node, its dist from src
        dist[k]=0;
    

        while(!pq.empty())
        {
            int u = pq.top().second;     // 1. pop the node
            int weight = pq.top().first;
            pq.pop();
            if(weight>dist[u]) continue;
            for(auto it: adj[u])    // 2. relax the neighbors
            {
                int curnode = it.first;
                int d = it.second;

                if(weight + d < dist[curnode])
                {
                    dist[curnode] = weight + d;

                    pq.push({dist[curnode], curnode});
                }
            }

        }
        int ans = *max_element(dist.begin()+1, dist.end());
        if(ans==INT_MAX)
        {
            return -1;
        }
        return ans;

    }
};
