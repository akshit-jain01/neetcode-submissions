class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> mp;    // to store last occurence of the character
        int n = s.size();
        for(int i = 0; i<n; i++)
        {
            mp[s[i]] = i;
        }
        vector<int> ans;
        int start = 0;
        int end = 0;
        for(int i = 0; i<n; i++)
        {
            end = max(end, mp[s[i]]);

            if(i==end)
            {
                int len = end-start+1;
                ans.push_back(len);

                start = i+1;
            }

        }
        return ans;
    }
};
