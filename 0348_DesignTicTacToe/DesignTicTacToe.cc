class TicTacToe {
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        size = n;
        board.resize(n);
        for (int i=0;i<n;++i) {
            board[i].resize(n, 0);
        }
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        board[row][col] = player;
        if (check(row, col, player)) return player;
        return 0;
    }
private:
    int size;
    vector<vector<int>> board;
    
    bool check(int row, int col, int player) {
        int countRow = 0, countCol = 0;
        for (int i=0;i<size;++i) {
            if (board[i][col] == player) ++countRow;
            if (board[row][i] == player) ++countCol;
        }
        if (countRow == size || countCol == size) return true;
        
        if (row == col) {
            int i = 0;
            for (;i<size;++i) {
                if (board[i][i] != player) break;
            }
            if (i == size) return true;
        }
        if (row + col == size-1) {
            int i=size-1;
            for (;i>=0;--i) {
                if (board[size-1-i][i] != player) break;
            }
            if (i<0) return true;
        }
        return false;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */

// Better:

class TicTacToe {
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        size = n;
        r.resize(n, 0);
        c.resize(n, 0);
        diag = antidiag = 0;
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        int add = player == 1 ? 1 : -1;
        r[row] += add;
        c[col] += add;
        if (row == col) diag += add;
        if (row + col == size-1) antidiag += add;
        if (r[row] == add*size || c[col] == add*size || diag == add*size || antidiag == add*size) return player;
        return 0;
    }
private:
    vector<int> r, c;
    int size;
    int diag, antidiag;
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */