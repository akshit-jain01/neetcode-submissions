class Solution {
public:
    int solve(int index, vector<int>& nums, vector<int>& dp)
    {
        if(index>=nums.size()-1)
        {
            return 0;
        }
        if(nums[index]==0)
        {
            return 1e9;
        }
        if(dp[index]!=-1) return dp[index];
        int temp = 1e9;
        for(int i = 1; i<= nums[index]; i++)
        {
            int next = 1 + solve(index+i, nums, dp);
            
            if(next!=1e9)
            {
                temp = min(temp, next);
            }
        }
        return dp[index] = temp;
    }
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return solve(0, nums, dp);
        
    }
};
