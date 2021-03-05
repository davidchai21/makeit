class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> res;
        for (string& word : words) {
            if (helper(word)) res.push_back(word);
        }
        return res;
    }
private:
    const vector<string> dic = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};
    
    inline int getIndex(const char& c) {
        if (dic[0].find(c) != string::npos) return 0;
        else if (dic[1].find(c) != string::npos) return 1;
        else if (dic[2].find(c) != string::npos) return 2;
        return -1;
    }
    
    bool helper(string& s) {
        int index = getIndex(tolower(s[0]));
        for (int i=1;i<s.size();++i) {
            if (dic[index].find(tolower(s[i])) == string::npos) return false;
        }
        return true;
    }
};