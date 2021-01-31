class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        unordered_map<int,int> m;
        for (int i=lowLimit; i<=highLimit; ++i) {
            ++m[getTotal(i)];
        }
        int res = 0;
        for (auto it = m.begin(); it != m.end(); ++it) {
            res = max(res, it->second);
        }
        return res;
    }
private:
    int getTotal(int n) {
        int res = 0;
        while (n) {
            res += n%10;
            n /= 10;
        }
        return res;
    }
};

// Better:

class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        int res = 0;
        vector<int> record(46, 0);
        for (int k=lowLimit; k<=highLimit; ++k) {
            int ans = 0;
            int n=k;
            while (n) {
                ans += n%10;
                n /= 10;
            }
            ++record[ans];
            res = max(res, record[ans]);
        }
        return res;
    }
};