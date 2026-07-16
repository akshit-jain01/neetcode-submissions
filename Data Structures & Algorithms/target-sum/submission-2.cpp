class Solution {
public:
    int solve(int index, vector<int>& nums, int target, int currsum)
    {
        if(index==nums.size())
        {
            return currsum==target;
        }
        if(index>nums.size())
        {
            return 0;
        }
        int plus = solve(index+1, nums, target, currsum+nums[index]);
        int minus = solve(index+1, nums, target, currsum-nums[index]);

        return plus + minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        return solve(0, nums, target, 0);
    }
};
