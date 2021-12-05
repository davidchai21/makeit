class UndergroundSystem {
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        record[id] = make_pair(stationName, t);
    }
    
    void checkOut(int id, string stationName, int t) {
        string s = getStr(record[id].first, stationName);
        if (m.find(s) == m.end()) m[s] = make_pair(0.0, 0);
        m[s].first += t-record[id].second;
        ++m[s].second;
    }
    
    double getAverageTime(string startStation, string endStation) {
        string key = getStr(startStation, endStation);
        return m[key].first / m[key].second;
    }
private:
    unordered_map<string, pair<double, int>> m;
    unordered_map<int, pair<string, int>> record;
    
    inline string getStr(string& a, string& b) {
        return a+"#"+b;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */