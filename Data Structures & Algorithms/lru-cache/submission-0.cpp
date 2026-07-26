class LRUCache {
public:
    struct Node{
        int key;
        int val;
        Node* next;
        Node* prev;

        Node(int key, int val)
        {   
            this->key = key;
            this->val = val;
        }
    };
    unordered_map<int, Node*> mp;   // stores key and its corresponding node
    int cap;
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    void addNode(int key, int val)
    {
        Node* temp = new Node(key, val);


        temp->next = head->next;
        head->next->prev = temp;
        temp->prev = head;
        head->next = temp;
    }

    void delNode(Node* del)
    {
        Node* nextone = del->next;
        Node* prevone = del->prev;

        nextone->prev = prevone;
        prevone->next = nextone;
    }
    LRUCache(int capacity) {
        cap = capacity;

        head->prev=NULL;
        head->next=tail;
        tail->prev=head;
        tail->next=NULL;
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end())
        {
            Node* temp = mp[key];
            mp.erase(key);
            delNode(temp);
            addNode(key, temp->val);
            mp[key] = head->next;
            int ival = temp->val;

            return ival;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key)==mp.end())
        {
            if(mp.size()==cap)
            {
                Node* del = tail->prev;
                delNode(del);
                mp.erase(del->key);
            }
        }
        else
        {
            Node* temp = mp[key];
            delNode(temp);
            mp.erase(key);

        }
        
        addNode(key, value);
        mp[key] = head->next;
    }
};
