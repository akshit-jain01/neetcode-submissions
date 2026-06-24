class MyHashMap {
public:
    int size;
    vector<vector<pair<int,int>>> HashMap;
    MyHashMap() {
        size = 10000;
        HashMap.resize(size);
    }
    
    void put(int key, int value) {
        int index = key%size;
        for(auto &[a,b]:HashMap[index])
        {
            if(a==key)
            {
                b=value;
                return;
            }
        }
        HashMap[index].push_back({key,value});
            
        
        
    }
    
    int get(int key) {
        int index = key%size;
        for(auto &[a,b]:HashMap[index])
        {
            if(a==key)
            {
                return b;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        int index = key%size;
        for(int i=0;i<HashMap[index].size();i++)
        {
            if(HashMap[index][i].first==key)
            {
                HashMap[index].erase(HashMap[index].begin()+i);
                return;
            }
        }   
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */