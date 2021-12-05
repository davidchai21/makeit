class Solution {
public:
    int maxA(int N) {
        vector<int> record(N+1, 0);
        for (int i=1;i<=N;++i) record[i] = i;
        for (int i=7;i<=N;++i) {
            for (int j=2;j<i-2;++j) {
                record[i] = max(record[i], (i-1-j)*record[j]);
            }
        }
        return record[N];
    }
};

// O(1) space:

class Solution {
public:
    int maxA(int N) {
        if (N <= 6) return N;
        array<int, 6> record;
        for (int i=0;i<6;++i) record[i] = i+1;
        for (int i=7;i<=N;++i) {
            int t = 0;
            for (int i=0;i<4;++i) {
                t = max(record[i]*(5-i), t);
            }
            for (int i=1;i<6;++i) {
                record[i-1] = record[i];
            }
            record.back() = t;
        }
        return record.back();
    }
};