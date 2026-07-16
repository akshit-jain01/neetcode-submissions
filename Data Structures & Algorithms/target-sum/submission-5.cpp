class Solution {
public:
    int solve(int index, vector<int>& nums, int target, int currsum, int offset, vector<vector<int>>& dp)
    {
        if(index==nums.size())
        {
            return currsum==target;
        }
        
        if(dp[index][currsum+offset]!=-1) return dp[index][currsum+offset];
        int plus = solve(index+1, nums, target, currsum+nums[index], offset, dp);
        int minus = solve(index+1, nums, target, currsum-nums[index], offset, dp);

        return dp[index][currsum+offset] = plus + minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();
        vector<vector<int>> dp(n , vector<int>(2*total+1, -1));
        return solve(0, nums, target, 0, total, dp);
    }
};
