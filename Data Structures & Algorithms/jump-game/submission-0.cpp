class Solution {
public:
    bool check(int index, vector<int>& nums)
    {
        if(index==nums.size()-1)
        {
            return true;
        }
        if(nums[index]==0 && index!=nums.size()-1)
        {
            return false;
        }
        int temp = nums[index];
        for(int i = 1; i<=temp;i++)
        {
            if(check(index+i, nums))
            return true;
        }
        return false;
    }
    bool canJump(vector<int>& nums) {
        return check(0, nums);
    }
};
