class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> res(m*n);
        int i = 0;
        int di=0;
        int l=0,r=n-1,u=0,d=m-1;
        int x=0,y=0;
        while (i<m*n) {
            res[i++] = matrix[x][y];
            switch(di) {
                case 0:
                    if (y+1>r) {
                        di = 1;
                        --r;
                    }
                    break;
                case 1:
                    if (x+1>d) {
                        di = 2;
                        --d;
                    }
                    break;
                case 2:
                    if (y-1<l) {
                        di = 3;
                        ++l;
                    }
                    break;
                case 3:
                    if (x-2<u) {
                        di = 0;
                        ++u;
                    }
                    break;
            }
            x += dir[di].first;
            y += dir[di].second;
        }
        return res;
    }
private:
    vector<pair<int,int>> dir = {{0,1}, {1,0}, {0,-1}, {-1,0}};
};