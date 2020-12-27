class Solution {
public:
    string freqAlphabets(string s) {
        int n = s.size();
        string res = "";
        for (int i=0;i<n;) {
            if (i+2<n && s[i+2]=='#') {
                res += 'a'+(s[i]-'0')*10+s[i+1]-'0'-1;
                i += 3;
            } else {
                res += 'a'+s[i++]-'0'-1;
            }
        }
        return res;
    }
};