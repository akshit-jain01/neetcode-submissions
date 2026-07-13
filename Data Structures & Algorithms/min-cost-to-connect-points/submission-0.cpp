class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        int n = points.size();
        vector<bool> vis(n, false);

        int numedges = 0;
        int cost = 0;

        pq.push({0, 0});    // distance from start, index of the point 

        while(!pq.empty())
        {
            auto [dist, node] = pq.top();
            pq.pop();

            if(vis[node])
            {
                continue;
            }

            vis[node] = true;
            numedges++;
            cost+=dist;

            if(numedges==n)
            {
                break;
            }

            for(int i = 0; i<n; i++)
            {
                if(!vis[i])
                {
                    int d = abs(points[node][0] - points[i][0]) + abs(points[node][1] - points[i][1]);

                    pq.push({d, i});
                }
            }
        }
        return cost;

    }
};
