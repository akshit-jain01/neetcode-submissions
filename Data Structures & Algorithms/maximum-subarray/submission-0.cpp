class Solution {
public:
    int solve(int index, vector<int>& nums, int currsum, int& maxSum)
    {
        if(index==nums.size())
        {
            return maxSum;
        }
        currsum += nums[index];
        maxSum = max(maxSum, currsum);
        if(currsum<=0)
        {
            currsum = 0;
        }
        return solve(index+1, nums, currsum, maxSum);
    }
    int maxSubArray(vector<int>& nums) {
        int s = INT_MIN;
        return solve(0, nums, 0, s);
    }
};
