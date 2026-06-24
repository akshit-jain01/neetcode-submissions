class Solution {
public:
    int maxArea(vector<int>& heights) {
        long maxArea = INT_MIN;
        long currentArea;
        vector<pair<int,int>> vols;

        for(int i=0;i<heights.size();i++)
        {
            vols.push_back({heights[i], i});
        }

        for(int i=0;i<vols.size();i++)
        {
            for(int j=i+1;j<vols.size();j++)
            {
                currentArea = min(vols[i].first, vols[j].first)*abs(j-i);
                if(currentArea>maxArea)
                maxArea=currentArea;
            }
        }
        return maxArea;
    }
};
