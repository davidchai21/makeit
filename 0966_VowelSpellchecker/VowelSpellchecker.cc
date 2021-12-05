class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> s;
        unordered_map<string, vector<int>> same, diff;
        for (int i=0;i<wordlist.size();++i) {
            s.insert(wordlist[i]);
            string skey = string(wordlist[i].size(), ' ');
            string dkey = string(wordlist[i].size(), ' ');
            for (int j=0;j<wordlist[i].size();++j) {
                skey[j] = tolower(wordlist[i][j]);
                dkey[j] = isVowel(wordlist[i][j]) ? '*' : tolower(wordlist[i][j]);
            }
            same[skey].push_back(i);
            diff[dkey].push_back(i);
        }
        
        vector<string> res(queries.size());
        for (int i=0;i<queries.size();++i) {
            if (s.find(queries[i]) != s.end()) res[i] = queries[i];
            else {
                string skey = string(queries[i].size(), ' ');
                string dkey = string(queries[i].size(), ' ');
                for (int j=0;j<queries[i].size();++j) {
                    skey[j] = tolower(queries[i][j]);
                    dkey[j] = isVowel(queries[i][j]) ? '*' : tolower(queries[i][j]);
                }
                
                if (same.find(skey) != same.end()) {
                    res[i] = wordlist[same[skey].front()];
                } else if (diff.find(dkey) != diff.end()) {
                    res[i] = wordlist[diff[dkey].front()];
                } else {
                    res[i] = "";
                }
            }
        }
        return res;
    }
private:
    inline bool isVowel(char& c) {
        char t = tolower(c);
        return t=='a' || t=='e' || t=='i' || t=='o' || t=='u';
    }
};