class Solution {
public:
    vector<int> grayCode(int n) {
        unordered_set<int> s({0});
        int size = 1<<n;
        vector<int> res(size, 0);
        for (int i=1;i<size;++i) {
            res[i] = getNext(s, res[i-1], n);
        }
        return res;
    }
private:
    int getNext(unordered_set<int>& s, int base, const int& n) {
        for (int i=0;i<n;++i) {
            base ^= 1<<i;
            if (s.find(base) == s.end()) {
                s.insert(base);
                return base;
            }
            base ^= 1<<i;
        }
        return -1;
    }
};

// Better:

class Solution {
public:
    vector<int> grayCode(int n) {
        int size = 1<<n;
        vector<int> res(size, 0);
        res[1] = 1;
        for (int d = 1; d<n;++d) {
            for (int len = (1<<d)-1, index = (1<<d); len>=0;--len) {
                res[index++] = res[len] | (1<<d);
            }
        }
        return res;
    }
};