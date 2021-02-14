class Solution {
public:
    int numDistinctIslands2(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        unordered_set<string> s;
        for (int i=0;i<m;++i) {
            for (int j=0;j<n;++j) {
                if (grid[i][j]) {
                    vector<pair<int,int>> record;
                    helper(grid, record, i, j, m, n);
                    save(record, s);
                }
            }
        }
        return s.size();
    }
private:
    const int N = 50;
    
    void helper(vector<vector<int>>& grid, vector<pair<int,int>>& record, int x, int y, int& m, int& n) {
        if (x<0 || y<0 || x>=m || y>=n || !grid[x][y]) return;
        grid[x][y] = 0;
        record.push_back(make_pair(x,y));
        
        helper(grid, record, x, y+1, m, n);
        helper(grid, record, x, y-1, m, n);
        helper(grid, record, x+1, y, m, n);
        helper(grid, record, x-1, y, m, n);
    }
    
    void save(vector<pair<int,int>>& record, unordered_set<string>& s) {
        vector<vector<pair<int,int>>> change(8);
        for (int i=0;i<8;++i) change[i].resize(record.size());
        for (int i=0;i<record.size();++i) {
            int x = record[i].first;
            int y = record[i].second;
            change[0][i] = make_pair(x,y);
            change[1][i] = make_pair(-x,y);
            change[2][i] = make_pair(x,-y);
            change[3][i] = make_pair(-x,-y);
            change[4][i] = make_pair(y,x);
            change[5][i] = make_pair(-y,x);
            change[6][i] = make_pair(y,-x);
            change[7][i] = make_pair(-y,-x);
        }
        for (int i=0;i<8;++i) {
            sort(change[i].begin(), change[i].end());
            int base_x = change[i][0].first;
            int base_y = change[i][0].second;
            for (pair<int,int>& p : change[i]) {
                p.first -= base_x;
                p.second -= base_y;
            }
        }
        sort(change.begin(), change.end());
        s.insert(getStr(change[0]));
    }
    
    string getStr(vector<pair<int,int>>& v) {
        string res = "";
        for (pair<int,int>& p : v) {
            res += to_string(p.first)+","+to_string(p.second)+"|";
        }
        return res;
    }
};