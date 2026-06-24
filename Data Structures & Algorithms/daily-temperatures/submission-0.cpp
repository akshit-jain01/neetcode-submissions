class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> indexes;
        int n = temperatures.size();
        vector<int> ans;
        for(int i=n-1;i>=0;i--)
        {
            while(!indexes.empty() && temperatures[i] >= indexes.top().first)
            {
                indexes.pop();
            }
            if(!indexes.empty())
            {
                int num = indexes.top().second - i;
                ans.push_back(num);
            }
            else
            {
                ans.push_back(0);
            }
            indexes.push({temperatures[i], i});
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
