class Solution {
public:
    bool solve(string s, vector<string>& wordDict, int index, vector<int>& dp)
    {
        if(index==s.size())
        {
            return true;
        }
        if(dp[index]!=-1) return dp[index];
        for(int i = index; i<s.size(); i++)
        {
            string temp = s.substr(index, i-index+1);

            for(string a : wordDict)
            {
                if(temp==a)
                {
                    if(solve(s, wordDict, i+1, dp))
                    return dp[index] = true;
                }
            }
        }
        return dp[index] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<int> dp(n, -1);
        return solve(s, wordDict, 0, dp);
    }
};
