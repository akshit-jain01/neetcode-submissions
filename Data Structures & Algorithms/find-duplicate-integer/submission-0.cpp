class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, int> mp;
        int num = 0;
        for(int e: nums)
        {
            mp[e]++;
        }

        for(auto it: mp)
        {
            if(it.second>1)
            {
                num = it.first;
            }
        }
        return num;
    }
};
