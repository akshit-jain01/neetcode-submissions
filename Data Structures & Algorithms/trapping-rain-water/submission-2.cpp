class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> leftmax(n);
        vector<int> rightmax(n);
        int lmax=height[0], rmax=height[n-1];

        for(int i=0;i<n;i++)
        {
            if(height[i]>lmax)
            {
                leftmax[i] = height[i];
                lmax = height[i];
            }
            else
            {
                leftmax[i] = lmax;
            }
        }

        for(int i=n-1;i>=0;i--)
        {
            if(height[i]>rmax)
            {
                rightmax[i] = height[i];
                rmax = height[i];
            }
            else
            {
                rightmax[i] = rmax;
            }
        }
        int ans = 0;        
        for(int i=0;i<n;i++)
        {
            ans+=min(leftmax[i], rightmax[i]) - height[i];
        }

        return ans;
    }
};
