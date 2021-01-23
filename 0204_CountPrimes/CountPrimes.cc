class Solution {
public:
    int countPrimes(int n) {
        if (n < 3) return 0;
        int res = 0;
        for (int i=2;i<n;++i) {
            if (isPrime(i)) ++res;
        }
        return res;
    }
private:
    bool isPrime(int n) {
        for (int i=2;i*i<=n;++i) {
            if (n%i==0) return false;
        }
        return true;
    }
};

// Extra Space:

class Solution {
public:
    int countPrimes(int n) {
        if (n<3) return 0;
        vector<bool> record(n, true);
        record[0] = record[1] = false;
        for (int i=2;i*i<n;++i) {
            if (!record[i]) continue;
            for (int j=i*i;j<n;j+=i) {
                record[j] = false;
            }
        }
        int res = 1;
        for (int i=3;i<n;++i) {
            if (record[i]) ++res;
        }
        return res;
    }
};