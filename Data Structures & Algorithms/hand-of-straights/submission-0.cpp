class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n%groupSize!=0) return false;
        sort(hand.begin(), hand.end());
        unordered_map<int,int> mp;
        for(int i : hand)
        {   
            mp[i]++;
        }
        for(int a : hand)
        {
            if(mp[a]==0)
            {
                continue;
            }

            for(int i = 0; i<groupSize; i++)
            {
                if(mp[a+i]==0)
                {
                    return false;
                }

                mp[a+i]--;
            }
        }
        
        
        return true;
    }
};
