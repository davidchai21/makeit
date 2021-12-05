class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        vector<int> stat(26, 0);
        for (char& c : B.front()) {
            ++stat[c-'a'];
        }
        for (int i=1;i<B.size();++i) {
            update(stat, B[i]);
        }
        
        vector<string> res;
        for (string& b : A) {
            if (check(stat, b)) res.push_back(b);
        }
        return res;
    }
private:
    void update(vector<int>& stat, string& s) {
        vector<int> t(26, 0);
        for (char& c: s) {
            ++t[c-'a'];
        }
        for (int i=0;i<26;++i) {
            stat[i] = max(stat[i], t[i]);
        }
    }
    
    bool check(const vector<int>& stat, string& s) {
        vector<int> t(26, 0);
        for (char& c : s) {
            ++t[c-'a'];
        }
        for (int i=0;i<26;++i) {
            if (t[i] < stat[i]) return false;
        }
        return true;
    }
};