class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& heights,  vector<vector<bool>>& vis)
    {
        if(vis[i][j])
        {
            return;
        }
        vis[i][j] = true;
        int m = heights.size();
        int n = heights[0].size();
        int delx[] = {-1, 0, 1, 0};
        int dely[] = {0, 1, 0, -1};

        for(int k = 0; k<4; k++)
        {
            int row = i + delx[k];
            int col = j + dely[k];

            if(row<m && col<n && row>=0 && col>=0 && heights[row][col]>=heights[i][j] && !vis[row][col])
            {
                dfs(row, col, heights, vis);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if(heights.empty() || heights[0].empty())
        return {};
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>> ans;
        vector<vector<bool>> pacific(m, vector<bool>(n, false));    // vector to store visited values
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));    // vector to store visited values
        
        for(int j = 0; j<n; j++)
        {
            dfs(0, j, heights, pacific);
        }
        for(int j = 0; j<m; j++)
        {
            dfs(j, 0, heights, pacific);
        }

        for(int j = 0; j<n; j++)
        {
            dfs(m-1, j, heights, atlantic);
        }
        for(int j = m-1; j>=0; j--)
        {
            dfs(j, n-1, heights, atlantic);
        }
        
        for(int i = 0;i <m; i++)
        {
            for(int j = 0; j<n;j++)
            {
                if(atlantic[i][j] && pacific[i][j])
                {
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
        
    }
};
