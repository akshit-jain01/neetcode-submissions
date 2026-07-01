class Solution {
public:
    vector<vector<int>> ans;
    set<vector<int>> temp;
    vector<int> curr;
    void dfs(int index, vector<int>& nums)
    {
        if(index == nums.size())
        {
            temp.insert(curr);
            return;
        }
        // take
        curr.push_back(nums[index]);
         
        //explore
        dfs(index+1, nums);

        //remove
        curr.pop_back();

        // not take
        dfs(index+1, nums);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        dfs(0, nums);
        for(auto it: temp)
        {
            ans.push_back(it);
        }
        return ans;
    }
};
