class Solution {
public:
    int maxLen = 1;
    int start = 0;
    void solve(int l, int r, string s)
    {
        while(l>=0 && r<s.size() && s[l]==s[r])
        {
            l--;
            r++;
        }
        int len = r - l - 1;
        if(len>maxLen)
        {
            maxLen = len;
            start = l+1;
        }
    }
    string longestPalindrome(string s) {
        
        for(int i = 0; i< s.size();i++)
        {
            solve(i, i, s);
            solve(i, i+1, s);
        }
        return s.substr(start, maxLen);
    }
};
