class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int x = 0, y = 0;
        for (int i=0;i<n;++i) {
            for (int j=0;j<n;++j) {
                if (board[i][j] == 'R') {
                    x = i, y = j;
                    i = n;
                    break;
                }
            }
        }
        
        int res = 0;
        for (int i=x+1;i<n;++i) {
            if (board[i][y] == '.') continue;
            else {
                if (board[i][y] == 'p') ++res;
                break;
            }
        }
        for (int i=x-1;i>=0;--i) {
            if (board[i][y] == '.') continue;
            else {
                if (board[i][y] == 'p') ++res;
                break;
            }
        }
        for (int i=y+1;i<n;++i) {
            if (board[x][i] == '.') continue;
            else {
                if (board[x][i] == 'p') ++res;
                break;
            }
        }
        for (int i=y-1;i>=0;--i) {
            if (board[x][i] == '.') continue;
            else {
                if (board[x][i] == 'p') ++res;
                break;
            }
        }
        return res;
    }
private:
    const int n = 8;
};