class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;

        for(int c : nums)
        {
            sum += c;
        }
        int n = nums.size();
        int actual = n*(n+1)/2;
        return actual - sum;
    }
};
