class MyHashMap {
public:
    int prime;
    vector<list<pair<int,int>>> mp;
    int hash(int key){
        return key%prime;
    }
    MyHashMap() {
        mp.resize((int)(1e4+10));
        prime= 10007;
    }
    
    void put(int key, int value) {
        int h= hash(key);
        auto &x = mp[h];
        for(auto &i:x)
        {
            if(i.first==key){
                i.second=value;return;
            }
        }
        mp[h].push_back({key,value});
    }
    
    int get(int key) {
        int h = hash(key);
        auto x=mp[h];
        for(auto i:x)
        {
            if(i.first==key)
                return i.second;
        }
        return -1;
    }
    
    void remove(int key) {
        int h= hash(key);
        auto &x= mp[h];
        for(auto &i:x)
        {
            if(i.first==key)
            {
                x.remove(i);
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