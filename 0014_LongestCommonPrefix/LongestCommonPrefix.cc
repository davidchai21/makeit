class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty() || strs.front().empty()) return "";
        if (strs.size() == 1) return strs.front();
        int len = strs.front().size();
        for (string& str : strs) len = min((int)str.size(), len);
        if (!len) return "";
        for (int i=0;i<len;++i) {
            for (int j=1;j<strs.size();++j) {
                if (strs.front()[i] != strs[j][i]) return strs.front().substr(0,i);
            }
        }
        return strs.front().substr(0, len);
    }
};