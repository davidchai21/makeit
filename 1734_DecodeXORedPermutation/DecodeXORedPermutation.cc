class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        int n = encoded.size()+1;
        int sum = 0;
        for (int i=1;i<=n;++i) sum ^= i;
        int temp = encoded[1];
        for (int i=3;i<n;i+=2) temp ^= encoded[i];
        vector<int> res(n, 0);
        res[0] = sum^temp;
        for (int i=1;i<n;++i) {
            res[i] = encoded[i-1]^res[i-1];
        }
        return res;
    }
};