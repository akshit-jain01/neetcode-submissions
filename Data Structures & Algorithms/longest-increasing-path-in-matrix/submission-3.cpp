class Solution {
public:
    int dfs(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        if(i>=m || j>=n)
        {
            return 0;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int best = 1;
        int delx[] = {-1, 0, 1, 0};
        int dely[] = {0, 1, 0, -1};
        for(int k = 0; k<4; k++)
        {
            int row = i + delx[k];
            int col = j + dely[k];

            if(row<m && col<n && row>=0 && col>=0 && matrix[row][col]>matrix[i][j])
            {
                best = max(best, 1 + dfs(row, col, matrix, dp));
            }
        }
        return dp[i][j] = best;
        
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int ans = INT_MIN;
        vector<vector<int>> dp(m, vector<int>(n, -1));

        for(int i = 0;i<m ;i++)
        {
            for(int j=0 ; j<n; j++)
            {
                ans = max(ans, dfs(i, j, matrix, dp));
            }
        }
        return ans;
    }
};
