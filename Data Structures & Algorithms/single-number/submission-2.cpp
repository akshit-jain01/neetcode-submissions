class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int first;
        first = 0;
        while(first < nums.size()-1)
        {
            if(nums[first]!=nums[first+1])
            {
                return nums[first];
                
            }
            first+=2;
        }

        return nums[first];
    }
};
