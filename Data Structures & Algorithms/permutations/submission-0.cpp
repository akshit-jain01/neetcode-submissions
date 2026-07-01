class Solution {
public:
    vector<vector<int>> ans;
    vector<int> curr;
    vector<bool> visited;
    void dfs(vector<int>& nums)
    {
        if(curr.size()==nums.size())
        {
            ans.push_back(curr);
            return;
        }
        
        for(int i = 0; i<nums.size();i++)
        {
            if(visited[i]) continue;

            visited[i] = true;
            curr.push_back(nums[i]);

            dfs(nums);

            visited[i] = false;
            curr.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        visited.resize(nums.size(), false);
        dfs(nums);
        return ans;
    }
};
