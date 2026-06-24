class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n == 0) return 0;
        int l=0, r=1;
        unordered_map<char, int> m;
        m[s[0]] = 0;
        int maxLen =1;
        

        while(r<n)
        {
            
            if(m.find(s[r])!=m.end())
            {
                l=max(l,m[s[r]]+1);
            }
            m[s[r]] = r;
            maxLen = max(r-l+1, maxLen);
            r++;
        }
        return maxLen;

    }
};
