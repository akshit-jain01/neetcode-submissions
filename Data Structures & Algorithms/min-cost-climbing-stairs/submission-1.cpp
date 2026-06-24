class Solution {
public:
    int solve(vector<int>& cost, int n, int index, vector<int>& dp)
    {
        if(index>=n)
        {
            return 0;
        }
        if(dp[index]!=-1) return dp[index];
        int ones = cost[index] + solve(cost, n, index+1, dp);
        int twos = cost[index] + solve(cost, n, index+2, dp);

        return dp[index] = min(ones, twos);

    }
    int minCostClimbingStairs(vector<int>& cost) {
        int c;
        int n = cost.size();
        vector<int> dp(n, -1);
        c = min(solve(cost, n, 0, dp), solve(cost,n, 1, dp));

        return c;
    }
};
