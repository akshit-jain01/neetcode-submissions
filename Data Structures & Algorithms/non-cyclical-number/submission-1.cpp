class Solution {
public:
    unordered_map<int, int> mp;
    bool check(int sum)
    {
        if(sum==1)
        {
            return true;
        }
        if(mp[sum])
        {
            return false;
        }
        mp[sum]=1;
        

        int res, dig;
        res = 0;
        while(sum)
        {
            dig = sum%10;
            dig = dig*dig;
            res += dig;
            sum/=10;
        }
        
        return check(res);
    }
    bool isHappy(int n) {
        return check(n);
    }
};
