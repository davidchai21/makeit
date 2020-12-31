class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        traverse(board);
        getAnswer(board);
    }
private:
    void traverse(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        for (int i=0;i<m;++i) {
            for (int j=0;j<n;++j) {
                updateCell(board, i, j, m, n);
            }
        }
    }
    
    void getAnswer(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        for (int i=0;i<m;++i) {
            for (int j=0;j<n;++j) {
                board[i][j] >>= 1;
            }
        }
    }
    
    void updateCell(vector<vector<int>>& board, int x, int y, int m, int n) {
        int res = 0;
        for (pair<int,int>& p: dir) {
            int _x = x+p.first;
            int _y = y+p.second;
            if (_x >=0 && _y>=0 && _x<m && _y<n && (board[_x][_y]&1)==1) ++res; 
        }
        if ((board[x][y]&1)==1 && res ==2 || res == 3) board[x][y] |= 2;
    }
    
    vector<pair<int,int>> dir = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
};