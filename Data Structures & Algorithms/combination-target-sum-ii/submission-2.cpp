class Solution {
public:
    vector<vector<int>> ans;
    
    vector<int> curr;
    void dfs(int start, vector<int>& nums, int target)
    {
        if(target == 0)
        {
            ans.push_back(curr);
            return;
        }

        
        
        for(int i = start;i<nums.size(); i++)
        {
            if(i> start  && nums[i] == nums[i-1])
            {
                continue;
            }

            if(nums[i]>target)
            {
                break;
            }
            curr.push_back(nums[i]);

            dfs(i+1, nums, target - nums[i]);

            curr.pop_back();
        }

        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(0, candidates, target);

        return ans;
    }
};
