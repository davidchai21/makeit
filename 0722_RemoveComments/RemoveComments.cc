class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        vector<string> res;
        bool inBlock = false;
        string str = "";
        for (string& s : source) {
            int i=0;
            while (i<s.size()) {
                if (inBlock && i<s.size()-1 && s[i]=='*' && s[i+1]=='/') {
                    inBlock = false;
                    i += 2;
                } else if (!inBlock && i<s.size()-1 && s[i]=='/' && s[i+1]=='/') {
                    break;
                } else if (!inBlock && i<s.size()-1 && s[i]=='/' && s[i+1]=='*') {
                    inBlock = true;
                    i += 2;
                } else if (!inBlock) {
                    str += s[i++];
                } else ++i;
            }
            if (!inBlock && !str.empty()) {
                res.push_back(str);
                str = "";
            }
        }
        return res;
    }
};