class Solution {
public:
    vector<vector<int>> ans;
    vector<int> curr;
    void dfs(int index, vector<int>& nums)
    {
        if(index==nums.size())
        {
            ans.push_back(curr);
            return;
        }

        curr.push_back(nums[index]);
        dfs(index+1, nums);    //take

        curr.pop_back();   // remove

        dfs(index+1, nums);   // move ahead without taking, no loop as once taken never taken in future

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(0, nums);
        return ans;
    }
};
