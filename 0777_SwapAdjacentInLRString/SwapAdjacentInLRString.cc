class Solution {
public:
    bool canTransform(string start, string end) {
        if (!match(start, end)) return false;
        
        int n = start.size();
        for (int i=0, j=0;i<n && j<n;) {
            if (start[i]=='X') ++i;
            else if (end[j]=='X') ++j;
            else {
                if (start[i]=='L' && i<j || start[i]=='R' && i>j || start[i] != end[j]) return false;
                ++i;
                ++j;
            }
        }
        return true;
    }
private:
    bool match(string& a, string& b) {
        int x = 0, l = 0, r = 0;
        for (char& c : a) {
            if (c=='X') ++x;
            else if (c=='L') ++l;
            else ++r;
        }
        for (char& c : b) {
            if (c=='X') --x;
            else if (c=='L') --l;
            else --r;
        }
        return !x && !l && !r;
    }
};