class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res(num+1, 0);
        for (int i=1;i<=num;++i) {
            res[i] = helper(i);
        }
        return res;
    }
private:
    int helper(int n) {
        int res = 0;
        while (n) {
            n &= n-1;
            ++res;
        }
        return res;
    }
};

// DP:

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res(num+1, 0);
        for (int i=1;i<=num;++i) {
            res[i] = res[i/2] + (i%2);
        }
        return res;
    }
};

// Another DP:

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res(num+1, 0);
        for (int i=1;i<=num;++i) {
            res[i] = res[i&(i-1)]+1;
        }
        return res;
    }
};