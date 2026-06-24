class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0;
        int maxLen = 0;
        int maxFreq = 0;
        int n = s.size();
        vector<int> freq(26, 0);

        for(int r = 0;r<n;r++)
        {
            freq[s[r]-'A']++;

            maxFreq = max(maxFreq, freq[s[r]-'A']);

            while((r-l+1)-maxFreq > k)     // check if elements other than max freq element are greater than k
            {
                freq[s[l]-'A']--;
                l++;
            }

            maxLen = max(r-l+1, maxLen);
        }

        return maxLen;

    }
};
