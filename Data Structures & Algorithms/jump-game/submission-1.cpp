class Solution {
public:
    bool check(int index, vector<int>& nums, vector<int>& dp)
    {
        if(index==nums.size()-1)
        {
            return true;
        }
        if(nums[index]==0 && index!=nums.size()-1)
        {
            return false;
        }
        if(dp[index]!=-1) return dp[index];
        int temp = nums[index];
        for(int i = 1; i<=temp;i++)
        {
            if(check(index+i, nums, dp))
            return dp[index] = true;
        }
        return dp[index] = false;
    }
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return check(0, nums, dp);
    }
};
