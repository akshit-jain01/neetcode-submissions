class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,double>> cars;
        for(int i = 0; i<position.size(); i++)
        {
            double time = (double)(target-position[i])/speed[i];
            cars.push_back({position[i], time});
        }
        sort(cars.begin(), cars.end(), [](auto &a, auto &b){
            return a.first < b.first;
        });
        stack<double> st;
        for(int i = cars.size()-1; i>=0; i--)
        {
            if(st.empty())
            {
                st.push(cars[i].second);
            }
            else if(st.top()<cars[i].second)
            {
                st.push(cars[i].second);
            }
            else
            {
                continue;
            }
        }
        return st.size();
    }
};
