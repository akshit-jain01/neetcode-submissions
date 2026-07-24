class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        for(string s : strs)
        {
            vector<int> freq(26, 0);
            for(int i = 0; i<s.size();i++)
            {
                freq[s[i]-'a']++;
            }
            string key = "";

            for(int i : freq)
            {
                key+= '#' + to_string(i);
            }
            m[key].push_back(s);
        }
        vector<vector<string>> ans;
        for(auto it: m)
        {
            ans.push_back(it.second);
        }

        return ans;
    }
};
