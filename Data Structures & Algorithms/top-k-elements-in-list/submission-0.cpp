class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;

        for(int x : nums)
        {
            m[x]++;
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        for(auto it: m)
        {
            int freq = it.second;
            int val = it.first;
            pq.push({freq, val});
            
            if(pq.size()>k)
            {
                pq.pop();
            }
        }

        vector<int> ans;

        while(!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
        

    }
};
