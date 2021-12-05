class Solution {
public:
    string reorganizeString(string S) {
        if (S.size() < 2) return S;
        vector<int> dic(26, 0);
        int maxCount = 0;
        for (char& c : S) {
            maxCount = max(maxCount, ++dic[c-'a']);
        }
        if (maxCount > (S.size()+1)/2) return "";
                
        return helper(dic);
    }
private:
    struct Cmp {
        bool operator() (pair<int, char>& a, pair<int, char>& b) {
            return a.first < b.first;
        }
    };
    
    string helper(vector<int>& dic) {
        priority_queue<pair<int, char>, vector<pair<int, char>>, Cmp> pq;
        for (int i=0;i<26;++i) {
            if (dic[i] > 0) {
                pq.push(make_pair(dic[i], 'a'+i));
            }
        }
        
        string res = "";
        while (!pq.empty()) {
            if (pq.size() == 1) {
                res.push_back(pq.top().second);
                return res;
            } else {
                pair<int, char> first = pq.top();
                pq.pop();
                pair<int, char> second = pq.top();
                pq.pop();
                if (res.empty() || res.back() != first.second) {
                    res.push_back(first.second);
                    --first.first;
                } else {
                    res.push_back(second.second);
                    --second.first;
                }
                if (first.first > 0) pq.push(first);
                if (second.first > 0) pq.push(second);
            }
        }
        return res;
    }
};

// Faster:

class Solution {
public:
    string reorganizeString(string S) {
        vector<int> record(26, 0);
        int maxFreq = 0;
        for (char& c : S) {
            maxFreq = max(maxFreq, ++record[c-'a']);
        }
        if (maxFreq > (S.size()+1)/2) return "";
        
        vector<pair<char,int>> table;
        for (int i=0;i<26;++i) {
            if (record[i] > 0) table.push_back(make_pair(i+'a', record[i]));
        }
        sort(table.begin(), table.end(), [](pair<char, int>& a, pair<char, int>& b) {
            return a.second > b.second;
        });
        
        int index = 0;
        for (pair<char, int>& t : table) {
            while (t.second--) {
                if (index >= S.size()) index = 1;
                S[index] = t.first;
                index += 2;
            }
        }
        return S;
    }
};