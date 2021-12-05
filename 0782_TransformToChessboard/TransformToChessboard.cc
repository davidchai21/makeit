class Solution {
public:
    int movesToChessboard(vector<vector<int>>& board) {
        int n = board.size();
        for (int i=0;i<n;++i) {
            for (int j=0;j<n;++j) {
                if (board[0][0]^board[0][j]^board[i][0]^board[i][j]) return -1;
            }
        }
        
        int row = 0, col = 0;
        int rowswap = 0, colswap = 0;
        for (int i=0;i<n;++i) {
            col += board[0][i];
            row += board[i][0];
            colswap += board[0][i]==(i%2);
            rowswap += board[i][0]==(i%2);
        }
        if (row != n/2 && row != (n+1)/2 || col != n/2 && col != (n+1)/2) return -1;
        
        if (n&1) {
            if (rowswap%2) rowswap = n-rowswap;
            if (colswap%2) colswap = n-colswap;
        } else {
            rowswap = min(rowswap, n-rowswap);
            colswap = min(colswap, n-colswap);
        }
        return (rowswap+colswap)>>1;
    }
};