class LRUCache {
public:
    int capacity;
    list<int> dll;
    unordered_map<int,pair<int,list<int>::iterator>> mp;
    LRUCache(int capacity) {
        this->capacity=capacity;
    }
    void makeMostRecentlyUsed(int key)
    {   
        dll.erase(mp[key].second);
        dll.push_front(key);
        mp[key].second = dll.begin();

}    

    int get(int key) {
        if(mp.find(key)==mp.end())
            return -1;
        makeMostRecentlyUsed(key);
        return mp[key].first;
    }
    
    void put(int key, int value) {
        if(capacity==0)
            return;
        if(mp.find(key)!=mp.end()){
            mp[key].first=value;
            makeMostRecentlyUsed(key);
        }else{
            dll.push_front(key);
            mp[key]={value,dll.begin()};

            if(dll.size()>capacity){
                int keyToDelete = dll.back();
                dll.pop_back();
                mp.erase(keyToDelete);
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */