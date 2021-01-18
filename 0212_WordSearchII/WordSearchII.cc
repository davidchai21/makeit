struct Node {
    bool isEnd = false;
    Node* child[26] = {};
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root = new Node();
        for (string& word : words) build(word);
        
        int m = board.size();
        int n = board[0].size();
        string s = "";
        vector<string> res;
        for (int i=0;i<m;++i) {
            for (int j=0;j<n;++j) {
                helper(board, m, n, i, j, res, s, root->child[board[i][j]-'a']);
            }
        }
        return res;
    }
private:
    Node* root;
    vector<pair<int,int>> dir = {{0,1}, {1,0}, {-1,0}, {0,-1}};
    
    void build(string& word) {
        Node* cur = root;
        for (char& c : word) {
            int pos = c-'a';
            if (!cur->child[pos]) cur->child[pos] = new Node();
            cur = cur->child[pos];
        }
        cur->isEnd = true;
    }
    
    void helper(vector<vector<char>>& board, int& m, int& n, int x, int y, vector<string>& res, string& s, Node* curNode) {
        if (!curNode) return;
        s.push_back(board[x][y]);
        if (curNode->isEnd) {
            curNode->isEnd = false;
            res.push_back(s);
        }

        char record = board[x][y];
        board[x][y] = '*';
        
        for (int i=0;i<4;++i) {
            int _x = x+dir[i].first;
            int _y = y+dir[i].second;
            if (isValid(m, n, _x, _y) && board[_x][_y]!='*') {
                helper(board, m, n, _x, _y, res, s, curNode->child[board[_x][_y]-'a']);
            }
        }
        board[x][y] = record;
        s.pop_back();
    }
    
    bool isValid(int& m, int& n, int x, int  y) {
        return x>=0 && y>=0 && x<m && y<n;
    }
};