class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> sums;
        vector<int> ans;
        for(int i=0;i<nums.size();i++)
        {
            int diff = target-nums[i];
            if(sums.find(diff)==sums.end())
            {
                sums.insert(make_pair(nums[i],i));
            }
            else
            {
                ans.push_back(sums[diff]);
                ans.push_back(i);
            }
        }
        return ans;
    }
};
