class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int left=0,right=1;
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size();i++)
        {
            if(i>0 && nums[i]==nums[i-1]) continue;
            
                
                int left=i+1;
                int right=nums.size()-1;
                while(left<right)
                {
                    if(nums[i]+nums[left]+nums[right]>0)
                    {
                        right--;
                    }
                    else if(nums[i]+nums[left]+nums[right]<0)
                    {
                        left++;
                    }
                    else
                    {
                        
                        ans.push_back({nums[i], nums[left], nums[right]});
                        left++;
                        while(left<right && nums[left]==nums[left-1])
                            left++;
                        
                    }
                    
                }
            

        }
        return ans;

    }
};
