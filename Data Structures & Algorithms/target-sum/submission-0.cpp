class Solution {
public:
    int solve(int index, vector<int>& nums, int target)
    {
        if(target==0 && index==nums.size())
        {
            return 1;
        }
        if(index>=nums.size())
        {
            return 0;
        }
        int plus = solve(index+1, nums, target+nums[index]);
        int minus = solve(index+1, nums, target-nums[index]);

        return plus + minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        return solve(0, nums, target);
    }
};
