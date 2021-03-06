class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> record(n, vector<int>(n,0));
        vector<vector<int>> maxTable(n, vector<int>(n,0));
        for (int i=n-1;i>=0;--i) {
            for (int j=i;j<n;++j) {
                if (i==j) maxTable[i][j] = arr[i];
                else maxTable[i][j] = max(arr[j], maxTable[i][j-1]);
            }
        }
        for (int i=n-2;i>=0;--i) {
            for (int j=i+1;j<n;++j) {
                if (j==i+1) record[i][j] = arr[i]*arr[j];
                else {
                    int ans = INT_MAX;
                    for (int k=i;k<j;++k) {
                        ans = min(ans, maxTable[i][k]*maxTable[k+1][j]+record[i][k]+record[k+1][j]);
                    }
                    record[i][j] = ans;
                }
            }
        }
        return record[0][n-1];
    }
};

// Stack:

class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        vector<int> st;
        st.push_back(INT_MAX);
        int res = 0;
        for (int& num : arr) {
            while (num >= st.back()) {
                int mid = st.back();
                st.pop_back();
                res += min(st.back(), num)*mid;
            }
            st.push_back(num);
        }
        for (int i=2;i<st.size();++i) {
            res += st[i-1]*st[i];
        }
        return res;
    }
};