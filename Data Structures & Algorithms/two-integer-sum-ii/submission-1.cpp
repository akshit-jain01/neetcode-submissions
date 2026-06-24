class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        // for(int i=0;i<numbers.size();i++)    // too inefficient
        // {
        //     for(int j=i+1;j<numbers.size();j++)
        //     {
        //         if(numbers[i]+numbers[j]==target)
        //         {
        //             ans.push_back(i+1);
        //             ans.push_back(j+1);
        //             return ans;
        //         }
                
        //     }
        // }
        int left=0, right=nums.size()-1;
        while(left<right)
        {
            if(nums[left]+nums[right]>target)
            {
                right--;
            }
            else if(nums[left]+nums[right]<target)
            {
                left++;
            }
            else
            {
                ans.push_back(left+1);
                ans.push_back(right+1);
                break;
            }
        }
        return ans;
    }
};
