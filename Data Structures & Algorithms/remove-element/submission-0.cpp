class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int> ans;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=val)
            {
                ans.push_back(nums[i]);
            }
        }
        nums.clear();
        for(int i=0;i<ans.size();i++)
        {
            nums.push_back(ans[i]);
        }
        return nums.size();
    }
};