class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<int> ans;
        vector<vector<int>> adj(numCourses);

        for(auto it: prerequisites)
        {
            int a = it[0];
            int b = it[1];

            adj[b].push_back(a);
            indegree[a]++;
        }

        queue<int> q;
        for(int i = 0; i<indegree.size(); i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }

        while(!q.empty())
        {
            int temp = q.front();
            ans.push_back(temp);
            q.pop();

            for(int i : adj[temp])
            {
                indegree[i]--;

                if(indegree[i]==0)
                {
                    q.push(i);
                }
            }
        }
        if(ans.size()!= numCourses)
        {
            return {};
        }
        return ans;

    }
};
