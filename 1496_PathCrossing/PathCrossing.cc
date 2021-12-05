class Solution {
public:
    bool isPathCrossing(string path) {
        unordered_set<string> s;
        int x = 0, y = 0;
        s.insert("0,0");
        for (char& c : path) {
            if (c=='N') ++y;
            else if (c=='S') --y;
            else if (c=='E') ++x;
            else --x;
            string cor = to_string(x)+","+to_string(y);
            if (s.find(cor) != s.end()) return true;
            s.insert(cor);
        }
        return false;
    }
};