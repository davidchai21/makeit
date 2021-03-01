class Solution {
public:
    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
        unordered_map<string, int> count;
        unordered_map<string, vector<pair<int, string>>> record;
        int n = username.size();
        for (int i=0;i<n;++i) {
            record[username[i]].push_back(make_pair(timestamp[i], website[i]));
        }
        for (auto it = record.begin(); it != record.end(); ++it) {
            if (it->second.size() < 3) continue;
            
            sort(it->second.begin(), it->second.end(), [](pair<int, string>& a, pair<int, string>& b){
                return a.first < b.first;
            });
            
            unordered_set<string> t;
            int size = it->second.size();
            for(int i=0;i<size-2;++i) {
                for (int j=i+1;j<size-1;++j) {
                    for (int k=j+1;k<size;++k) {
                        t.insert(getStr(it->second[i].second, it->second[j].second, it->second[k].second));
                    }
                }
            }
            
            for (auto tit = t.begin(); tit != t.end(); ++tit) {
                ++count[*tit];
            }
        }
        
        int times = 0;
        string res = "";
        for (auto it = count.begin(); it != count.end(); ++it) {
            if (it->second > times) {
                times = it->second;
                res = it->first;
            } else if (it->second == times) {
                if (res.compare(it->first) > 0) res = it->first;
            }
        }
        return decode(res);
    }
private:
    string getStr(string& a, string& b, string& c) {
        return a + " " + b + " " + c;
    }
    
    vector<string> decode(string& str) {
        stringstream ss(str);
        string word;
        vector<string> res;
        while (ss >> word) {
            res.push_back(word);
        }
        return res;
    }
};