class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int area = 0;
        int n = heights.size();
        for(int i=0;i<=n;i++)
        {
            int curheight = (i==n)?0:heights[i];

            while(!st.empty() && heights[st.top()]>curheight)
            {
                int height = heights[st.top()];
                st.pop();

                int width;
                if(st.empty())
                {
                    width = i;
                }
                else
                {
                    width = i - st.top() - 1;
                }
                area = max(area, width * height);
            }
            st.push(i);
        }
        return area;
    }
};
