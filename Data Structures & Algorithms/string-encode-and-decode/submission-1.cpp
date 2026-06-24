class Solution {
public:

    string encode(vector<string>& strs) {
        string temp = "";

        for(int i=0;i<strs.size();i++)
        {
            temp+=to_string(strs[i].size());
            temp+='#';
            temp+=strs[i];            
        }

        return temp;
    }

    vector<string> decode(string s) {
        vector<string> ans;

        for(int i=0;i<s.size();)
        {
            string temp = "";
            int len = 0;
            while(s[i]!='#')
            {
                len = len*10 + (s[i]-'0');
                i++;
            }
            
            
            i++;
            while(len--)
            {
                temp+=s[i++];
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
