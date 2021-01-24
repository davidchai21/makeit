class Solution {
public:
    string maximumTime(string time) {
        return getHour(time.substr(0,2)) + ":" + getMinute(time.substr(3));
    }
private:
    string getHour(string h) {
        if (h[0] == '?' && h[1] == '?') {
            h = "23";
        } else if (h[0] == '?' && h[1] != '?') {
            int k = h[1]-'0';
            if (k < 4) h[0] = '2';
            else h[0] = '1';
        } else if (h[0] != '?' && h[1] == '?') {
            if (h[0] == '2') h[1] = '3';
            else h[1] = '9';
        }
        return h;
    }
    
    string getMinute(string m) {
        if (m[0] == '?' && m[1] == '?') m = "59";
        else if (m[0] == '?' && m[1] != '?') {
            m[0] = '5';
        } else if (m[0] != '?' && m[1] == '?') {
            m[1] = '9';
        }
        return m;
    }
};