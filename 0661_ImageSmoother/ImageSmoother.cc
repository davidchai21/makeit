class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        const int bit = 8;
        const vector<pair<int,int>> dir = {{-1,-1}, {-1,0}, {-1,1}, {0,-1}, {0,1}, {1,-1}, {1,0}, {1,1}};
        int m = M.size(), n = M[0].size();
        for (int i=0;i<m;++i) {
            for (int j=0;j<n;++j) {
                int sum = M[i][j] & 0xff;
                int d = 1;
                for (const pair<int,int>& p : dir) {
                    int x = i+p.first;
                    int y = j+p.second;
                    if (x>=0 && y>=0 && x<m && y<n) {
                        sum += (M[x][y] & 0xff);
                        ++d;
                    }
                }
                int val = sum/d;
                M[i][j] |= val<<bit;
            }
        }
        for (int i=0;i<m;++i) {
            for (int j=0;j<n;++j) {
                M[i][j] >>= bit;
            }
        }
        return M;
    }
};