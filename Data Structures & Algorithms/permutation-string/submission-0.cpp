class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m = s2.size();
        int n = s1.size();
        vector<int> check(26, 0);
        for(int i=0;i<n;i++)
        {
            check[s1[i]-'a']++;
        }
        for(int i=0;i<m;i++)
        {
            vector<int> temp(26, 0);
            for(int j=i; j<m && j<i+n;j++)
            {
                temp[s2[j]-'a']++;
            }
            if(temp==check)
            {
                return true;
            }
        }
        return false;
    }
};
