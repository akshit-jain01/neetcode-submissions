class Solution {
public:
    bool isPalindrome(string s) {
        s.erase(std::remove(s.begin(), s.end(), ' '), s.end());
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        s.erase(std::remove_if(s.begin(), s.end(), [](char c) {
        return !std::isalnum(c);
    }), s.end());

        int i,j;
        for(i=0,j=s.size()-1;i<=s.size()/2;i++,j--)
        {
            if(s[i]!=s[j])
            {
                return false;
            }
        }
        return true;
    }
};
