class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> adj(numCourses);
        for(auto it: prerequisites)
        {
            int a = it[0];
            int b = it[1];
            adj[b].push_back(a);
            indegree[a] ++;
        }
        queue<int> q;
        for(int i = 0; i<indegree.size();i++){
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        int count=0;
        while(!q.empty())
        {
            int temp = q.front();
            q.pop();
            count++;
            for(int i : adj[temp])
            {
                indegree[i]--;
                if(indegree[i]==0)
                {
                    q.push(i);
                }
            }
        }

        return numCourses==count;
    }
};
