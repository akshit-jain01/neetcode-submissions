class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        unordered_map<char,int> sno;
        unordered_map<char,int> tno;

        for(int i=0;i<s.size();i++)
        {
            if(sno.find(s[i])==sno.end())
            {
                sno.insert(make_pair(s[i],1));
            }
            else
            sno[s[i]]++;
        }

        for(int i=0;i<s.size();i++)
        {
            if(tno.find(t[i])==tno.end())
            {
                tno.insert(make_pair(t[i],1));
            }
            else
            tno[t[i]]++;
        }
        for(auto it:sno)
        {
            if(tno.find(it.first)==tno.end())
            return false;
            else
            {
                if(it.second!=tno[it.first])
                return false;
            }
        }
        return true;
    }
};
