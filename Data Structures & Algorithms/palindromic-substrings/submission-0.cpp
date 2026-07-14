class Solution {
public:
    int count = 0;
    int solve(int l, int r, string s)
    {
        while(l>=0 && r<s.size() && s[l]==s[r])
        {
            l--;
            r++;

            count++;
        }
        return count;
    }
    int countSubstrings(string s) {
        for(int i = 0; i<s.size();i++)
        {
            solve(i, i, s);
            solve(i, i+1, s);
        }
        return count;
    }
};
