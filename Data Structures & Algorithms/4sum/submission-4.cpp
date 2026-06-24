class Solution {
    vector<vector<int>> ans;
    vector<int> quad;
public:

    void kSum(int k, int start, long long target, vector<int>& nums)
    {
        if(k!=2)
        {
            for(int i=start;i<nums.size()-k+1;i++)
            {
                if(i>start && nums[i]==nums[i-1])
                continue;
                
                quad.push_back(nums[i]);
                kSum(k-1, i+1, target-nums[i], nums);
                quad.pop_back();
            }
            return;
        }
        int l=start, r=nums.size()-1;
        while(l<r)
        {
            if(nums[l]+nums[r]<target)
            l++;
            else if(nums[l]+nums[r]>target)
            r--;
            else
            {
                quad.push_back(nums[l]);
                quad.push_back(nums[r]);
                ans.push_back(quad);
                quad.pop_back();
                quad.pop_back();
                l++;
                r--;
                while (l < r && nums[l] == nums[l - 1]) l++;
                while (l < r && nums[r] == nums[r + 1]) r--;
            }
        }
        return;
    }

    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if(nums.size()<4) return{};
        sort(nums.begin(), nums.end());
        
        kSum(4, 0, (long)(long)target, nums);

        return ans;
    }
};