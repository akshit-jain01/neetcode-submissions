class Solution {
public:
    int solve(string &w1, string &w2, int i, int j, vector<vector<int>>& dp)
    {
        if(i<0)
        {
            return j+1;
        }
        if(j<0)
        {
            return i+1;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(w1[i]==w2[j])
        {
            return dp[i][j] = solve(w1, w2, i-1, j-1, dp);
        }
        int insert = 1 + solve(w1, w2, i-1, j, dp);
        int idelete = 1 + solve(w1, w2, i, j-1, dp);
        int ireplace = 1 + solve(w1, w2, i-1, j-1, dp);

        return dp[i][j] = min({insert, idelete, ireplace});
    }
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        return solve(word1, word2, m, n, dp);
    }
};
