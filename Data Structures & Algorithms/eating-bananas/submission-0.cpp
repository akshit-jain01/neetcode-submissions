class Solution {
public:
    int eatHrs(int k, vector<int>&piles)
    {
        int hours = 0;
        for(int pile : piles)
        {
            hours += (pile + k - 1)/k;   // for positive integers works as ceil(pile/k)
        }
        return hours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int ans;

        while(low<=high)
        {
            int mid = low+(high-low)/2;
            int hrs = 0;
            if(eatHrs(mid, piles)<=h)
            {
                ans = mid;
                high = mid-1;
            }
            else
            {
                low = mid+1;
            }
        }
        return ans;
    }
};
