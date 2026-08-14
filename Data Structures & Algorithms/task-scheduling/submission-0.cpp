class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> mp(26,0);

        for(char ch:tasks)
        {
            mp[ch-'A']++;
        }
        int maxFreq = 0;
        for(int it:mp)
        {
            if(it>maxFreq)
            {
                maxFreq = it;
            }
        }
        int maxCount = 0;
        for(int it:mp)
        {
            if(it==maxFreq)
            {
                maxCount++;
            }
        }
        int slots = maxFreq-1;

        int emptyslots = slots*n;

        int remtasks = tasks.size() - maxFreq;

        int idle = max(0, emptyslots - remtasks);
        int ans = (maxFreq-1)*(n+1) + maxCount;

        return max((int)tasks.size(), ans);
    }
};
