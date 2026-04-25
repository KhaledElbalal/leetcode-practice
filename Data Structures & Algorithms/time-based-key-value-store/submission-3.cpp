class TimeMap {
public:

    unordered_map<string, vector<pair<string,int>>> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) { 
        mp[key].push_back({value, timestamp});
        cout << mp[key].size() << endl;
    }
    
    string get(string key, int timestamp) {
        auto& v = mp[key];
        if(v.empty() || v[0].second > timestamp) return "";
        int low = 0, high = v.size() - 1;
        while(low < high) {
            int mid = (low + high + 1) / 2;  // ceiling mid
            if(v[mid].second <= timestamp) {
                low = mid;
            } else {
                high = mid - 1;
            }
        }
        return v[low].first;
    }
};
