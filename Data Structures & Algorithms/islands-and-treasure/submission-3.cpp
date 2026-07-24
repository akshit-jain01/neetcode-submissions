class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int m = grid.size();
        if(m==0) return;
        int n = grid[0].size();
        
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        
        for(int i = 0; i<m; i++)
        {
            for(int j = 0 ; j<n; j++)
            {
                if(grid[i][j]==0)
                {
                    q.push({i,j});
                    vis[i][j]=true;
                    dist[i][j] = 0;
                }
            }
        }
        int delx[] = {-1, 0, 1, 0};
        int dely[] = {0, 1, 0, -1};
        while(!q.empty())
        {
            auto temp = q.front();
            q.pop();

            int i = temp.first;
            int j = temp.second;

            for(int k = 0; k<4;k++)
            {
                int row = i + delx[k];
                int col = j + dely[k];
                if(row<m && col<n && row>=0 && col>=0 && grid[row][col]==2147483647 && !vis[row][col])
                {
                    q.push({row, col});
                    vis[row][col] = true;
                    dist[row][col] = dist[i][j]+1;
                }
            }

        }
        for(int i = 0; i<m; i++)
        {
            for(int j = 0; j <n; j++)
            {
                if(grid[i][j]==2147483647)
                {
                    grid[i][j] = dist[i][j];
                }
            }
        }
    }
};
