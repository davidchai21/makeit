class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i=0;i<m;++i) {
            for (int j=0;j<n;++j) {
                if (helper(word, board, i, j, m, n, 0, visited)) return true;
            }
        }
        return false;
    }
private:
    vector<pair<int,int>> dir = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    
    bool helper(string& word, vector<vector<char>>& board, int x, int y, int& m, int& n, int index, vector<vector<bool>>& visited) {
        if (index == word.size()) return true;
        if (!isValid(x, y, m, n) || visited[x][y] || board[x][y] != word[index]) return false;
        
        visited[x][y] = true;
        bool res = false;
        for (int i=0;i<4;++i) {
            int _x = x+dir[i].first;
            int _y = y+dir[i].second;
            if (helper(word, board, _x, _y, m, n, index+1, visited)) {
                res = true;
                break;
            }
        }
        visited[x][y] = false;
        return res;
    }
    
    bool isValid(int x, int y, int& m, int& n) {
        if (x < 0 || y < 0 || x >= m || y >= n) return false;
        return true;
    }
};