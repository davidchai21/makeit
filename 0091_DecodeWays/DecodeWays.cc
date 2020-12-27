class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if (!n || s.front()=='0') return 0;
        if (n==1) return 1;
        int pre = 1;
        int cur = 1;
        for (int i=1;i<n;++i) {
            if (s[i]=='0') {
                if (s[i-1]=='0' || s[i-1]>'2') return 0;
                swap(cur, pre);
            } else {
                if (s[i-1]=='0') pre = cur;
                else {
                    int sum = (s[i-1]-'0')*10+s[i]-'0';
                    if (sum>26) pre = cur;
                    else {
                        int t = cur + pre;
                        pre = cur;
                        cur = t;
                    }
                }
            }
        }
        return cur;
    }
};