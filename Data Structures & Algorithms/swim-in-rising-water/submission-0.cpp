class Solution {
public:
    vector<vector<bool>> vis;
    bool dfs(int i, int j, vector<vector<int>>& grid, int t)
    {
        int n = grid.size();
        if(grid[0][0]>t)
        {
            return false;
        }
        if(vis[i][j])
        {
            return false;
        }
        if(i==n-1 && j==n-1)
        {
            return true;
        }
        vis[i][j] = true;

        int delx[] = {-1, 0, 1, 0};
        int dely[] = {0, 1, 0, -1};

        for(int k = 0; k<4; k++)
        {
            int row = i + delx[k];
            int col = j + dely[k];

            if(row<n && row >= 0 && col <n && col >=0 && !vis[row][col] && grid[row][col]<=t)
            {
                if(dfs(row, col, grid, t))
                return true;
            }
        }
        return false;
    }
    int swimInWater(vector<vector<int>>& grid) {
        int low = 0, high = 0;
        int n = grid.size();
        
        low = max(grid[0][0], grid[n-1][n-1]);
        for(int i = 0 ;i <n; i++)
        {
            for(int j = 0; j<n; j++)
            {
                high = max(high, grid[i][j]);
            }
        }
         
        while(low<=high)
        {
            int mid = low+(high-low)/2;

            vis.assign(n, vector<bool>(n, false));

            if(dfs(0, 0, grid, mid))
            {
                high = mid-1;
            }
            else
            {
                low = mid+1;
            }
            
        }
        return low;

    }
};
