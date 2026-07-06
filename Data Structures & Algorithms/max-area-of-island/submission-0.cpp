class Solution {
public:
    int maxArea = 0;
    vector<vector<bool>> visited; 
    int dfs(int i, int j, vector<vector<int>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        if(i<0 || j<0)
        {
            return 0;
        }

        if(i>=m || j>=n)
        {
            return 0;
        }
        
        if(grid[i][j]==0)
        {
            return 0;
        }
        if(visited[i][j])
        {
            return 0;
        }

        int delx[] = {-1, 0, 1, 0};
        int dely[] = {0, 1, 0, -1};

        int area = 1;
        visited[i][j] = true;
        for(int k = 0; k<4; k++)
        {

            int row = i + delx[k];
            int col = j + dely[k];

            if(row<m && row>=0 && col<n && col>=0 && !visited[row][col] && grid[row][col]==1)
            {
                area += dfs(row, col, grid);
            }
        }

        return area;

    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int area = 0;

        visited.resize(m, vector<bool>(n, false));

        for(int i = 0;i < m; i++)
        {
            for(int j = 0; j<n;j++)
            {
                if(!visited[i][j] && grid[i][j]==1)
                {
                    area = dfs(i, j, grid);
                }
                maxArea = max(area, maxArea);
            }
        }
        return maxArea;
    }
};
