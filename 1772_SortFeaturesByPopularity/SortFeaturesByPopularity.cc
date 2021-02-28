class Solution {
public:
    vector<string> sortFeatures(vector<string>& features, vector<string>& responses) {
        int n = features.size();
        vector<string> res(n);
        vector<int> count(n, 0);
        unordered_map<string, int> m;
        for (int i=0;i<n;++i) m[features[i]] = i;
        
        for (string& response : responses) {
            stringstream ss(response);
            string word;
            unordered_set<string> s;
            while (ss >> word) {
                s.insert(word);
            }
            for (auto it = s.begin(); it != s.end(); ++it) {
                if (m.find(*it) != m.end()) ++count[m[*it]];
            }
        }
        
        vector<pair<int,int>> record(n);
        for (int i=0;i<n;++i) {
            record[i] = make_pair(count[i], i);
        }
        sort(record.begin(), record.end(), [](pair<int,int>& a, pair<int,int>& b){
            return a.first > b.first || a.first == b.first && a.second < b.second;
        });
        for (int i=0;i<n;++i) {
            res[i] = features[record[i].second];
        }
        return res;
    }
};