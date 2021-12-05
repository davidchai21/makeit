class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        for (int i=0;i<m;++i) {
            if (board[i][0] == 'O') change(board, 'O', 'A', i, 0, m, n);
            if (board[i][n-1] == 'O') change(board, 'O', 'A', i, n-1, m, n);
        }
        for (int i=0;i<n;++i) {
            if (board[0][i] == 'O') change(board, 'O', 'A', 0, i, m, n);
            if (board[m-1][i] == 'O') change(board, 'O', 'A', m-1, i, m, n);
        }
        
        for (int i=1;i<m-1;++i) {
            for (int j=1;j<n-1;++j) {
                if (board[i][j] == 'O') change(board, 'O', 'X', i, j, m, n);
            }
        }
        for (int i=0;i<m;++i) {
            for (int j=0;j<n;++j) {
                if (board[i][j] == 'A') board[i][j] = 'O';
            }
        }
    }
private:
    void change(vector<vector<char>>& board, const char base, const char target, int x, int y, const int& m, const int& n) {
        if (x<0 || y<0 || x>=m || y>=n || board[x][y] != base) return;
        board[x][y] = target;
        
        change(board, base, target, x+1, y, m, n);
        change(board, base, target, x-1, y, m, n);
        change(board, base, target, x, y+1, m, n);
        change(board, base, target, x, y-1, m, n);
    }
};