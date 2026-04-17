class MyHashSet {
public:
    vector<vector<int>> vec;
    vector<vector<bool>> included;
    MyHashSet() {
        vec = vector<vector<int>> (1000);
        included = vector<vector<bool>> (1000);
    }

    int calculateHash(int key) {
        int val = key + 10007;
        val /= 2;
        return val % 1000;
    }
    
    void add(int key) {
        int hash = calculateHash(key);
        for(int i = 0; i < vec[hash].size(); i++) {
            if(vec[hash][i] == key) {
                included[hash][i] = true;
                return;
            }
        }
        included[hash].push_back(true);
        vec[hash].push_back(key);
    }
    
    void remove(int key) {
        int hash = calculateHash(key);
        for(int i = 0; i < vec[hash].size(); i++) {
            if(vec[hash][i] == key) {
                included[hash][i] = false;
                return;
            }
        }
    }
    
    bool contains(int key) {
        int hash = calculateHash(key);
        for(int i = 0; i < vec[hash].size(); i++) {
            if(vec[hash][i] == key && included[hash][i] == true) {
                return true;
            }
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */