class Solution {
public:
    string addBinary(string a, string b) {
        if (a == "0" || b == "0") return a=="0" ? b : a;
        string res(max(a.size(), b.size())+1, '0');
        int digit = 0;
        int i = a.size()-1, j = b.size()-1;
        int index = res.size()-1;
        while (index >= 0) {
            if (i >= 0) digit += a[i--]-'0';
            if (j >= 0) digit += b[j--]-'0';
            res[index--] = digit%2 ? '1' : '0';
            digit >>= 1;
        }
        return res.front() == '0' ? res.substr(1) : res;
    }
};