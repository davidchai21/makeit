class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        unordered_map<int, vector<int>> mp;
        for (int i=0;i<m;++i) {
            for (int j=0;j<n;++j) {
                mp[j-i].push_back(mat[i][j]);
            }
        }
        for (auto it = mp.begin(); it != mp.end(); ++it) {
            sort(it->second.begin(), it->second.end());
            int x = 0, y = 0;
            if (it->first < 0) x = -it->first;
            else y = it->first;
            for (int i=0;i<it->second.size();++i) {
                mat[x+i][y+i] = it->second[i];
            }
        }
        return mat;
    }
};

// O(m,n) space:

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        vector<int> t;
        int m = mat.size();
        int n = mat[0].size();
        for (int k=1-m;k<n;++k) {
            int x = k<0? -k : 0;
            int y = k<0? 0 : k;
            for (int i=x, j=y; i<m && j<n;++i, ++j) {
                t.push_back(mat[i][j]);
            }
            sort(t.begin(), t.end());
            auto it = t.begin();
            for (int i=x, j=y; it != t.end();++i, ++j, ++it) {
                mat[i][j] = *it;
            }
            t.clear();
        }
        return mat;
    }
};