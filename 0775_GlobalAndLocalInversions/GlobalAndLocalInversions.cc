class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
        int min_num = A.size();
        for (int i=A.size()-1;i>=2;--i) {
            min_num = min(min_num, A[i]);
            if (A[i-2] > min_num) return false;
        }
        return true;
    }
};

// Another:

class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
        for (int i=0;i<A.size();++i) {
            if (abs(A[i]-i) > 1) return false;
        }
        return true;
    }
};