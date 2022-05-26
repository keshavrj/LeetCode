class LRUCache {
private:
    int cap;
    unordered_map<int,list<pair<int,int>>::iterator> mp; //key, {key,value}::iterator;
    list<pair<int,int>> recent; //key,value;
public:
    LRUCache(int capacity) {
        cap= capacity;
    }
    int get(int key) {
        auto it= mp.find(key);
        if(it==mp.end())return -1;
        recent.splice(recent.begin(),recent,it->second);
        return it->second->second; // return it->list->second;
    }
    void put(int key, int value) {
        auto it= mp.find(key);
        if(it!=mp.end()){
            recent.splice(recent.begin(), recent, it->second);
            it->second->second= value;
            return;
        }
        if(mp.size()==cap){
            int old= recent.back().first;
            recent.pop_back();
            mp.erase(old);
        }
        recent.push_front({key,value});
        mp[key]=recent.begin();
    }
};