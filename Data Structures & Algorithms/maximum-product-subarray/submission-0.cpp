class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int> maxDp(n);
        vector<int> minDp(n);
        int ans = nums[0];
        maxDp[0] = nums[0];
        minDp[0] = nums[0];
        for(int i = 1; i<n; i++)
        {
            int c = nums[i];

            maxDp[i] = max({c, c*maxDp[i-1], c*minDp[i-1]});
            minDp[i] = min({c, c*maxDp[i-1], c*minDp[i-1]});

            ans = max(ans, maxDp[i]);
        }

        return ans;
    }
};
