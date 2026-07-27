class MedianFinder {
public:
    priority_queue<int> maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;
    void balance()
    {
        if(maxheap.size()>minheap.size()+1)
        {
            minheap.push(maxheap.top());
            maxheap.pop();
        }
        else if(minheap.size() > maxheap.size()+1)
        {
            maxheap.push(minheap.top());
            minheap.pop();
        }
    }
    MedianFinder() {
    }
    
    void addNum(int num) {
        if(maxheap.empty() || num <= maxheap.top())
        {
            maxheap.push(num);
        }
        else
        {
            minheap.push(num);
        }
        balance();
    }
    
    double findMedian() {
        if((maxheap.size()+minheap.size())%2==0)
        {
            return (maxheap.top()+minheap.top())/2.0;
        }
        else
        {
            if(maxheap.size()>minheap.size())
            {
                return maxheap.top();
            }
        }
        return minheap.top();
    }
};
