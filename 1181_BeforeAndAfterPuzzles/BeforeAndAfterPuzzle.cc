class Solution {
public:
    vector<string> beforeAndAfterPuzzles(vector<string>& phrases) {
        unordered_map<string, vector<int>> prefix;
        for (int i=0;i<phrases.size();++i) {
            prefix[getPrefix(phrases[i])].push_back(i);
        }
        set<string> s;
        for (int i=0;i<phrases.size();++i) {
            string suffix = getSuffix(phrases[i]);
            if (prefix.find(suffix) == prefix.end()) continue;
            for (const int& index : prefix[suffix]) {
                if (i != index) s.insert(phrases[i] + getRest(phrases[index]));
            }
        }
        return vector<string>(s.begin(), s.end());
    }
private:
    inline string getPrefix(string& str) {
        int index = 0;
        while (index < str.size() && str[index] != ' ') ++index;
        return str.substr(0,index);
    }
    
    inline string getSuffix(string& str) {
        int index = str.size()-1;
        while (index >= 0 && str[index] != ' ') --index;
        return index < 0 ? str : str.substr(index+1);
    }
    
    inline string getRest(string& str) {
        size_t pos = str.find(' ');
        if (pos == string::npos) return "";
        return str.substr(pos);
    }
};