class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> count;
        int ans;
        for(int i : nums)
        {
            count[i]++;
        }

        for(auto it: count)
        {
            if(it.second == 1)
            {
                ans = it.first;
            }
        }
        return ans;
    }
};
