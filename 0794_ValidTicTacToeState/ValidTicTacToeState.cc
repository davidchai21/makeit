class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        int countX = 0, countO = 0;
        for (string& s : board) {
            for (char& c : s) {
                if (c=='O') ++countO;
                if (c=='X') ++countX;
            }
        }
        if (countO > countX || countX > countO+1) return false;
        
        bool winX = false, winO = false;
        for (int i=0;i<3;++i) {
            if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
                if (board[i][0] == 'X') winX = true;
                if (board[i][0] == 'O') winO = true;
            }
            if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
                if (board[0][i] == 'X') winX = true;
                if (board[0][i] == 'O') winO = true;
            }
        }
        if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
            if (board[0][0] == 'X') winX = true;
            if (board[0][0] == 'O') winO = true;
        }
        if (board[2][0] == board[1][1] && board[1][1] == board[0][2]) {
            if (board[2][0] == 'X') winX = true;
            if (board[2][0] == 'O') winO = true;
        }
        if (winX && winO) return false;
        if (winX) return countX > countO;
        if (winO) return countX == countO;
        return true;
    }
};