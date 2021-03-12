class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        vector<vector<bool>> record(n, vector<bool>(m, false));
        int res = 0;
        for (vector<int>& indice : indices) {
            addRow(record, indice[0], m, res);
            addCol(record, indice[1], n, res);
        }
        return res;
    }
private:
    inline void addRow(vector<vector<bool>>& record, const int& row, const int& n, int& res) {
        for (int i=0;i<n;++i) {
            record[row][i] = !record[row][i];
            record[row][i] ? ++res : --res;
        }
    }
    
    inline void addCol(vector<vector<bool>>& record, const int& col, const int& n, int& res) {
        for (int i=0;i<n;++i) {
            record[i][col] = !record[i][col];
            record[i][col] ? ++res : --res;
        }
    }
};

// Better:

class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        vector<bool> row(n, false);
        vector<bool> col(m, false);
        for (vector<int>& index : indices) {
            row[index[0]] = row[index[0]]^true;
            col[index[1]] = col[index[1]]^true;
        }
        int r=0, c=0;
        for (int i=0;i<n;++i) r += row[i];
        for (int i=0;i<m;++i) c += col[i];
        return r*m + c*n - 2*r*c;
    }
};