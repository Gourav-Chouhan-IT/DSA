class LRUCache {
    int cap;
    list<pair<int,int>> dll; 
    unordered_map<int, list<pair<int,int>>::iterator> mp;
public:
    LRUCache(int capacity) : cap(capacity) {}

    int get(int key) {
        if (!mp.count(key)) return -1;
        dll.splice(dll.begin(), dll, mp[key]); 
        return mp[key]->second;
    }

    void put(int key, int value) {
        if (mp.count(key)) {
            dll.erase(mp[key]);
        } else if (dll.size() == cap) {
            int lruKey = dll.back().first;
            dll.pop_back();
            mp.erase(lruKey);
        }
        dll.push_front({key, value});
        mp[key] = dll.begin();
    }
};