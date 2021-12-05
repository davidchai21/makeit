class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n = words.size();
        int len = 0;
        vector<int> t;
        vector<string> res;
        for (int i=0;i<n;++i) {
            if (len == 0) {
                len = words[i].size();
                t.push_back(i);
            } else {
                if (len+1+words[i].size() <= maxWidth) {
                    len += 1+words[i].size();
                    t.push_back(i);
                } else {
                    if (t.size() == 1) {
                        string s = words[t[0]];
                        s.resize(maxWidth, ' ');
                        res.push_back(s);
                    } else {
                        int k = t.size()-1;
                        len -= k;
                        int q = (maxWidth-len)/k;
                        int r = (maxWidth-len)%k;
                        string s(maxWidth, ' ');
                        int i=0;
                        for (;i<words[t[0]].size();++i) {
                            s[i] = words[t[0]][i];
                        }
                        for (int j=1;j<t.size();++j) {
                            int size = q + (r-->0);
                            while (size--) s[i++] = ' ';
                            for (char& c : words[t[j]]) {
                                s[i++] = c;
                            }
                        }
                        res.push_back(s);
                    }
                    len = words[i].size();
                    t.clear();
                    t.push_back(i);
                }
            }
        }
        string s = words[t[0]];
        for (int i=1;i<t.size();++i) {
            s += " " + words[t[i]];
        }
        s.resize(maxWidth, ' ');
        res.push_back(s);
        return res;
    }
};