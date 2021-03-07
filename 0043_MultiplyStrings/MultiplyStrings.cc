class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        int m = num1.size(), n = num2.size();
        vector<int> res;
        for (int i=0;i<m;++i) {
            int a = num1[m-1-i]-'0';
            int digit = 0;
            for (int j=0;j<n;++j) {
                digit += a*(num2[n-1-j]-'0');
                if (i+j < res.size()) {
                    digit += res[i+j];
                    res[i+j] = digit%10;
                } else {
                    res.push_back(digit%10);
                }
                digit /= 10;
            }
            int index = i+n;
            while (digit) {
                if (index >= res.size()) res.push_back(digit%10);
                else {
                    digit += res[index];
                    res[index] = digit%10;
                }
                digit /= 10;
                ++index;
            }
        }
        string ans = "";
        for (auto it = res.rbegin(); it != res.rend(); ++it) {
            ans.push_back(*it+'0');
        }
        return ans;
    }
};

// No reverse:

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        int m = num1.size(), n = num2.size();
        string res(m+n, '0');
        for (int i=0;i<m;++i) {
            int digit = 0;
            int num = num1[m-1-i] - '0';
            for (int j=0;j<n;++j) {
                digit += (num2[n-1-j]-'0')*num + res[m+n-1-i-j] - '0';
                res[m+n-1-i-j] = digit%10 + '0';
                digit /= 10;
            }
            if (digit) res[m-1-i] = digit + '0';
        }
        size_t pos = 0;
        while (pos < m+n && res[pos] == '0') ++pos;
        return res.substr(pos);
    }
};