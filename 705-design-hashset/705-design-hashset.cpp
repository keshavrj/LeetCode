class MyHashSet {
public:
    // vector<bool> hash;
    vector<list<int>> hash;
    int prime;
    int pos(int key)
    {
        return key%prime;
    }
    list<int>::iterator search_list(int key)
    {
        int h = pos(key);
        return find(hash[h].begin(), hash[h].end(), key);
    }
    
    MyHashSet() {
        prime=1007;
        // hash.assign(prime);
        hash.resize(prime);
    }
    
    void add(int key) {
        // hash[key]=true;
        int h= pos(key);
        auto it= search_list(key);
        if(it==hash[h].end())
            hash[h].push_back(key);
    }
    
    void remove(int key) {
        // hash[key]=false;
        int h= pos(key);
        auto it= search_list(key);
        if(it!=hash[h].end())
            hash[h].erase(it);
    }
    
    bool contains(int key) {
        // return hash[key];
        int h= pos(key);
        return search_list(key)!=hash[h].end();
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */