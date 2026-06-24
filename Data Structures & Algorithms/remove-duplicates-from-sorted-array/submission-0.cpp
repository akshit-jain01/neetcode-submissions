class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        map<int,int> count;
        for(int i=0;i<nums.size();i++)
        {
            if(count.find(nums[i])==count.end())
            {
                count.insert(make_pair(nums[i],1));
            }
            else
            {
                count[nums[i]]++;
            }
        }
        nums.erase(nums.begin(), nums.end());
        for(auto it:count)
        {
            nums.push_back(it.first);
        }
        return nums.size();
    }
};