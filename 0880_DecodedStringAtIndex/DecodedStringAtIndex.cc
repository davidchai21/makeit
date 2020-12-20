class Solution {
public:
    string decodeAtIndex(string S, int K) {
        int n = S.size();
        long long count = 1;
        for (int i=1;i<n;++i) {
            if (isalpha(S[i])) ++count;
            else count *= S[i]-'0';
        }
        for (int i=n-1;i>=0;--i) {
            K %= count;
            if (K==0 && isalpha(S[i])) return string(1,S[i]);
            if (isdigit(S[i])) count /= S[i]-'0';
            else --count;
        }
        return "";
    }
};