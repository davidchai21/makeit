class Solution {
public:
    string entityParser(string text) {
        string res = "";
        string t = "";
        int count = 0;
        unordered_map<string, string> m;
        m["&amp"] = "\&";
        m["&quot"] = "\"";
        m["&apos"] = "'";
        m["&gt"] = ">";
        m["&lt"] = "<";
        m["&frasl"] = "/";
        for (char& c : text) {
            if (c == '&') {
                if (!count) {
                    count = 1;
                } else {
                    res += t;
                }
                t = "&";
            } else if (c == ';') {
                if (count == 1) {
                    if (m.find(t) != m.end()) {
                        res += m[t];
                    } else {
                        res += t+";";
                    }
                    t = "";
                    count = 0;
                } else {
                    res.push_back(';');
                }
            } else {
                if (count == 1) t.push_back(c);
                else res.push_back(c);
            }
        }
        if (count) res += t;
        return res;
    }
};