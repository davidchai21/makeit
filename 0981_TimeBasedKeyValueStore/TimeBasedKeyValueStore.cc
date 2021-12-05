class TimeMap {
public:
    /** Initialize your data structure here. */
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        m[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        auto mp = &m[key];
        auto it = mp->lower_bound(timestamp);
        if (it->first == timestamp) return it->second;
        else if (it != mp->begin()) {
            --it;
            return it->second;
        }
        return "";
    }
private:
    unordered_map<string, map<int, string>> m;
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */