class SubrectangleQueries {
public:
    SubrectangleQueries(vector<vector<int>>& rectangle) {
        rec = rectangle;
    }
    
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        record.push_back({row1, col1, row2, col2, newValue});
    }
    
    int getValue(int row, int col) {
        for (int i=record.size()-1;i>=0;--i) {
            if (isInRange(record[i], row, col)) return record[i].back();
        }
        return rec[row][col];
    }
private:
    vector<vector<int>> rec;
    vector<vector<int>> record;
    
    inline bool isInRange(const vector<int>& v, const int& row, const int& col) {
        return row>=v[0] && row<=v[2] && col>=v[1] && col<=v[3];
    }
};

/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
 * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj->getValue(row,col);
 */

// Brute-force:

class SubrectangleQueries {
public:
    SubrectangleQueries(vector<vector<int>>& rectangle) {
        rec = &rectangle;
    }
    
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        for (int i=row1;i<=row2;++i) {
            for (int j=col1;j<=col2;++j) {
                (*rec)[i][j] = newValue;
            }
        }
    }
    
    int getValue(int row, int col) {
        return (*rec)[row][col];
    }
private:
    vector<vector<int>> *rec;
};

/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
 * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj->getValue(row,col);
 */