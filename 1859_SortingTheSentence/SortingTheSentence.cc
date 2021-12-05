class Solution {
public:
    string sortSentence(string s) {
        vector<string> record(10, "");
        stringstream ss(s);
        string word;
        while (ss >> word) {
            record[word.back()-'0'] = word.substr(0, word.size()-1);
        }
        
        string res = "";
        for (int i=1;i<10 && !record[i].empty(); ++i) {
            if (!res.empty()) res.push_back(' ');
            res += record[i];
        }
        return res;
    }
};