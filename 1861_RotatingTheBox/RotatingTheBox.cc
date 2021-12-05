class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size();
        int n = box[0].size();
        vector<vector<char>> res(n, vector<char>(m));
        for (int i=0;i<m;++i) {
            for (int right = n-1; right >= 0;) {
                if (box[i][right] == '*') {
                    res[right][m-1-i] = '*';
                    --right;
                } else {
                    int left = right;
                    int count = 0;
                    while (left >= 0 && box[i][left] != '*') {
                        if (box[i][left] == '#') ++count;
                        --left;
                    }
                    while (right > left) {
                        if (count > 0) {
                            res[right][m-1-i] = '#';
                            --count;
                        } else {
                            res[right][m-1-i] = '.';
                        }
                        --right;
                    }
                }
            }
        }
        return res;
    }
};

// Better:

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size(), n = box[0].size();
        vector<vector<char>> res(n, vector<char>(m, '.'));
        for (int i=0;i<m;++i) {
            int pos = n;
            for (int j=n-1;j>=0;--j) {
                if (box[i][j] == '.') continue;
                else if (box[i][j] == '#') {
                    res[--pos][m-1-i] = '#';
                } else {
                    pos = j;
                    res[j][m-1-i] = '*';
                }
            }
        }
        return res;
    }
};