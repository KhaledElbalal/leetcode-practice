class LRUCache {
public:
    unordered_map<int,pair<int,list<int>::const_iterator>> mp;
    list<int> li;
    int cap;
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(mp.contains(key)) {
            li.erase(mp[key].second);
            li.push_back(key);
            mp[key] = {mp[key].first, prev(li.end())};
            return mp[key].first;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.contains(key)) {
            li.erase(mp[key].second);
        } else if(li.size() == cap) {
            auto it = li.begin();
            mp.erase(*it);
            li.erase(it);
        }
        li.push_back(key);
        mp[key] = {value, prev(li.end())};
    }
};
