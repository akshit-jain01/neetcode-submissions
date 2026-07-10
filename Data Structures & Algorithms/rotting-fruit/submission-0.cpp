class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<pair<int,int>,int>> q; 
        int ans = 0;
        for(int i = 0;i<m ;i++)
        {
            for(int j = 0; j<n;j++)
            {
                if(grid[i][j] == 2)
                {
                    grid[i][j] = 2;
                    q.push({{i, j}, 0});   // coordinates and time
                }
            }
        }

        while(!q.empty())
        {
            auto temp = q.front();
            int i = temp.first.first;
            int j = temp.first.second;
            int t = temp.second;

            q.pop();
            
            ans = max(ans, t);
            int delx[] = {-1, 0, 1, 0};
            int dely[] = {0, 1, 0, -1};

            for(int k = 0; k<4; k++)
            {
                int row = i + delx[k];
                int col = j + dely[k];

                if(row<m && row>=0 && col<n && col>=0 && grid[row][col]==1)
                {
                    q.push({{row, col}, t+1});
                    grid[row][col] = 2;
                }
            }

        }

        for(int i = 0; i<m;i++)
        {
            for(int j = 0; j<n; j++)
            {
                if(grid[i][j]==1)
                {
                    return -1;
                }
            }
        }
        return ans;
    }
};
