class Solution {
public:
    bool check(int index, int open, string s, vector<vector<int>>& dp)
    {
        if(index==s.size())
        {
            return open==0;
        }
        if(dp[index][open]!=-1) return dp[index][open];
        if(s[index]=='(')
        {
            return check(index+1, open+1, s,dp);
        }
        else if(s[index]==')')
        {
            if(open==0)
            {
                return false;
            }
            else
            {
                return check(index+1, open-1, s, dp);
            }
        }
        
        return dp[index][open] = check(index+1, open+1, s, dp) || (open>0 && check(index+1, open-1, s, dp) || check(index+1, open, s, dp));
        
        
    }
    bool checkValidString(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return check(0, 0, s, dp);
    
    }
};
