class Solution {
public:
    vector<vector<int>> ans;
    vector<int> curr;
    void dfs(int index, vector<int>& nums, int target, int cursum)
    {
        if(cursum == target)
        {
            ans.push_back(curr);
            return;
        }

        if(index==nums.size() || cursum > target) 
        return;
        // take the element
        
        curr.push_back(nums[index]);

        // explore further
        dfs(index, nums, target, cursum + nums[index]);

        //remove the element
        curr.pop_back();

        // move further not picking the element
        dfs(index+1, nums, target, cursum);
    }
    
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        dfs(0, nums, target, 0);

        return ans;
    }
};
