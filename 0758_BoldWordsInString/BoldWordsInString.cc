class Solution {
public:
    string boldWords(vector<string>& words, string S) {
        vector<pair<int,int>> s;
        for (string& word : words) {
            int n = word.size();
            for (int i=0;(i=S.find(word, i)) != string::npos; ++i) {
                s.push_back({i, i+n});
            }
        }
        if (s.empty()) return S;
        
        sort(s.begin(), s.end());
        vector<pair<int, int>> record;
        for (pair<int,int>& c : s) {
            if (record.empty() || record.back().second < c.first) {
                record.push_back(c);
            } else {
                record.back().second = max(record.back().second, c.second);
            }
        }
        
        string res = "";
        int end = 0;
        for (pair<int,int> c : record) {
            res += S.substr(end, c.first-end);
            res += "<b>" + S.substr(c.first, c.second-c.first) + "</b>";
            end = c.second;
        }
        res += S.substr(end);
        return res;
    }
};