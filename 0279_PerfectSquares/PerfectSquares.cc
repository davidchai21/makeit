class Solution {
public:
    int numSquares(int n) {
        if (n < 4) return n;
        vector<int> record(n+1,n+1);
        record[0] = 0;
        record[1] = 1;
        for (int i=2;i<=n;++i) {
            for (int j=1;j*j<=i;++j) {
                record[i] = min(record[i], 1+record[i-j*j]);
            }
        }
        return record[n];
    }
};

// BFS:

class Solution {
public:
    int numSquares(int n) {
        vector<int> dic;
        for (int i=1;i*i<=n;++i) dic.push_back(i*i);
        unordered_set<int> q;
        q.insert(n);
        int res = 1;
        while (!q.empty()) {
            int size = q.size();
            unordered_set<int> t;
            for (auto it = q.begin(); it != q.end(); ++it) {
                int base = *it;
                for (int i=0;i<dic.size();++i) {
                    if (base == dic[i]) return res;
                    else if (base-dic[i] < 0) break;
                    t.insert(base-dic[i]);
                }
            }
            q.swap(t);
            ++res;
        }
        return -1;
    }
};