class Solution {
public:
    unordered_map<char, string> m = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };
    string curr;
    vector<string> ans;
    void solve(int index, string digits)
    {
        if(digits == "")
        {
            return;
        }
        if(index==digits.size())
        {
            ans.push_back(curr);
            return ;
        }
        string numbers = m[digits[index]];
        for(char c : numbers)
        {
            curr.push_back(c);
            solve(index+1, digits);
            curr.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        solve(0,digits);

        return ans;
    }
};