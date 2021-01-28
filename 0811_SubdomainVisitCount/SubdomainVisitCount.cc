class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> m;
        for (string cp : cpdomains) {
            stringstream ss(cp);
            string f, domain;
            ss>>f>>domain;
            helper(m, stoi(f), domain);
        }
        
        vector<string> res(m.size());
        int index = 0;
        for (auto it = m.begin(); it!=m.end();++it) {
            res[index++] = getStr(it->first, it->second);
        }
        return res;
    }
private:
    void helper(unordered_map<string, int>& m, int f, string& domain) {
        m[domain] += f;
        size_t pos = 0;
        for(;;) {
            pos = domain.find('.', pos+1);
            if (pos == string::npos) return;
            m[domain.substr(pos+1)] += f;
        }
    }
    
    string getStr(string a, int b) {
        return to_string(b) + " " + a;
    }
};