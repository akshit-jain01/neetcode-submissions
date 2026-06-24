class MyHashSet {
public:
    vector<list<int>> buckets;
    int size;
    MyHashSet() {
        size = 10000;
        buckets = vector<list<int>>(size, list<int>{});
    }
    
    void add(int key) {
        int index = key%size;
        auto iter = find(buckets[index].begin(), buckets[index].end(), key);

        if(iter==buckets[index].end())
        {
            buckets[index].push_back(key);
        }
    }
    
    void remove(int key) {
        int index = key%size;
        auto iter = find(buckets[index].begin(), buckets[index].end(), key);

        if(iter!=buckets[index].end())
        {
            buckets[index].erase(iter);
        }
    }
    
    bool contains(int key) {
        int index = key%size;
        auto iter = find(buckets[index].begin(), buckets[index].end(), key);

        if(iter==buckets[index].end())
        {
            return false;
        }
        return true;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */