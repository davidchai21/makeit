class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        vector<vector<char>> board(3, vector<char>(3, '*'));
        for (int i=0;i<moves.size();++i) {
            char player = i%2 ? 'B' : 'A';
            place(board, moves[i][0], moves[i][1], player);
            string curRes = judge(board);
            if (!curRes.empty()) return curRes;
        }
        return moves.size() >= 9 ? "Draw" : "Pending";
    }
private:
    void place(vector<vector<char>>& board, int x, int y, char& player) {
        board[x][y] = player;
    }
    
    string judge(vector<vector<char>>& board) {
        for (int i=0;i<3;++i) {
            if (board[i][0] != '*' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) return string(1, board[i][0]);
            if (board[0][i] != '*' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) return string(1, board[0][i]);
        }
        if (board[0][0] != '*' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) return string(1, board[0][0]);
        if (board[0][2] != '*' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) return string(1, board[0][2]);
        return "";
    }
};

// Shorter:

class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        vector<int> A(8,0), B(8,0);
        for (int i=0;i<moves.size();++i) {
            vector<int>& player = i%2 ? B : A;
            string p = i%2 ? "B" : "A";
            if (++player[moves[i][0]] == 3) return p;
            if (++player[moves[i][1]+3] == 3) return p;
            if (moves[i][0] == moves[i][1]) ++player[6];
            if (moves[i][0]+moves[i][1] == 2) ++player[7];
            if (player[6] == 3 || player[7]==3) return p;
        }
        return moves.size() >= 9 ? "Draw" : "Pending";
    }
};