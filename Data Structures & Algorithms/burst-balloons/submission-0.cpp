class Solution {
public:
    int solve(vector<int>& arr, int l, int r, vector<vector<int>>& dp)
    {
        if(l+1==r)
        {
            return 0;
        }
        if(dp[l][r]!=-1) return dp[l][r];
        int ans = 0;
        for(int k = l+1; k<r;  k++)
        {
            int temp = solve(arr, l, k, dp) + solve(arr, k, r, dp) + arr[l]*arr[k]*arr[r];
            ans = max(ans, temp);
        }

        return dp[l][r] = ans;
    }
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr;
        arr.push_back(1);
        for(int i : nums)
        {
            arr.push_back(i);
        }
        arr.push_back(1);
        vector<vector<int>> dp(n+2, vector<int>(n+2, -1));

        return solve(arr, 0, arr.size()-1, dp);
    }
};
