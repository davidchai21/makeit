class Solution {
public:
    int kthFactor(int n, int k) {
        for (int i=1;i<=n;++i) {
            if (n%i==0) {
                --k;
                if (!k) return i;
            }
        }
        return -1;
    }
};

// O(n)

class Solution {
public:
    int kthFactor(int n, int k) {
        double root = sqrt(n);
        for (int i=1;i<root;++i) {
            if (n%i==0 && !--k) return i;
        }
        for (int i=root;i>=1;--i) {
            if (n%i==0 && !--k) return n/i;
        }
        return -1;
    }
};

// O(sqrt(n))