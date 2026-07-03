class Solution {
public:
    vector<vector<string>> ans;
    bool isPalindrome(string s, int l, int r)
    {
        while(l<=r)
        {
            if(s[l]!=s[r])
            return false;

            l++;
            r--;
        }
        return true;
    }
    void solve(string s, int index, vector<string> path)
    {
        if(index==s.size())
        {
            ans.push_back(path);
        }

        for(int end = index; end < s.size(); end++)
        {
            if(isPalindrome(s, index, end))
            {
                // take
                path.push_back(s.substr(index, end-index+1));

                //explore
                solve(s, end+1, path);

                //remove
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> path;
        solve(s, 0, path);

        return ans;
    }
};
