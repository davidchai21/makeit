class Solution {
public:
    string getHint(string secret, string guess) {
        int n = secret.size();
        vector<int> A(10, 0), B(10, 0);
        int x = 0, y = 0;
        for (int i=0;i<n;++i) {
            if (secret[i] == guess[i]) ++x;
            else {
                ++A[secret[i]-'0'];
                ++B[guess[i]-'0'];
            }
        }
        for (int i=0;i<10;++i) {
            y += min(A[i], B[i]);
        }
        return to_string(x)+"A"+to_string(y)+"B";
    }
};