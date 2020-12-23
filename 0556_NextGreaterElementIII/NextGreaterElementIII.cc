class Solution {
public:
    int nextGreaterElement(int n) {
        long num = 0L;
        vector<int> digit;
        while (n) {
            digit.push_back(n%10);
            n /= 10;
        }
        int pos = 1;
        for (;pos<digit.size();++pos) {
            if (digit[pos] < digit[pos-1]) break;
        }
        if (pos == digit.size()) return -1;
        int start = pos-1;
        for (int j=pos-1;j>=0;--j) {
            if (digit[j] > digit[pos]) start = j;
        }
        swap(digit[start], digit[pos]);
        for (int i=digit.size()-1;i>=pos;--i) {
            num = num*10+digit[i];
        }
        for (int i=0;i<pos;++i) {
            num = num*10+digit[i];
        }
        if (num > INT_MAX) return -1;
        return num;
    }
};