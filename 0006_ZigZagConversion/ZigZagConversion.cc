class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        int n = s.size();
        string res(n,'a');
        int index = 0;
        
        for (int i=0;i<n;i+=2*(numRows-1)) {
            res[index++] = s[i];
        }
        
        for (int i=1;i<numRows-1;++i) {
            for (int j=0;j+i<n;j+=2*(numRows-1)) {
                res[index++] = s[i+j];
                int t = j+2*(numRows-1)-i;
                if (t < n) res[index++] = s[t];
            }
        }
        
        for (int i=numRows-1;i<n;i+=2*(numRows-1)) {
            res[index++] = s[i];
        }
        return res;
    }
};