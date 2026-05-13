class MyHashMap {
public:

    int calculateHash(int key) {
        int val = key + 1000000007;
        val /= 2;
        return val % 1000;
    }

    vector<vector<pair<int,int>>> vec;
    vector<vector<bool>> included;

    MyHashMap() {
        vec = vector<vector<pair<int,int>>> (1000);
        included = vector<vector<bool>> (1000);
    }
    
    void put(int key, int value) {
        int hashVal = calculateHash(key);
        bool found = false;
        for(int i = 0; i < vec[hashVal].size(); i++) {
            if(vec[hashVal][i].first == key) {
                included[hashVal][i] = true;
                vec[hashVal][i].second = value;
                found = true;
            }
        }
        if(!found) {
            vec[hashVal].push_back({key,value});
            included[hashVal].push_back(true);
        }
    }
    
    int get(int key) {
        int hashVal = calculateHash(key);
        for(int i = 0; i < vec[hashVal].size(); i++) {
            if(vec[hashVal][i].first == key && included[hashVal][i]) {
                return vec[hashVal][i].second;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        int hashVal = calculateHash(key);
        for(int i = 0; i < vec[hashVal].size(); i++) {
            if(vec[hashVal][i].first == key && included[hashVal][i]) {
                included[hashVal][i] = false;
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