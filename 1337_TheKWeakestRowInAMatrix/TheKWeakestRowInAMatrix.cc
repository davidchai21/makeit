class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        vector<pair<int,int>> record(m);
        for (int i=0;i<m;++i) {
            record[i] = make_pair(count(mat[i].begin(), mat[i].end(), 1), i);
        }
        sort(record.begin(), record.end());
        vector<int> res(k);
        for (int i=0;i<k;++i) res[i] = record[i].second;
        return res;
    }
};

// Better:

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> res(k);
        int index = 0;
        for (int i=0;i<m && index<k;++i) {
            if (!mat[i][0]) res[index++] = i;
        }
        if (index == k) return res;
        
        for (int j=1;j<n && index<k;++j) {
            for (int i=0;i<m && index<k;++i) {
                if (!mat[i][j] && mat[i][j-1]) res[index++] = i;
            }
        }
        if (index == k) return res;
        
        for (int i=0;i<m && index<k;++i) {
            if (mat[i].back()) res[index++] = i;
        }
        return res;
    }
};