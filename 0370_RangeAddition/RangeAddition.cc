class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> record(length+1, 0);
        for (vector<int>& update : updates) {
            record[update[0]] += update[2];
            record[update[1]+1] -= update[2];
        }
        vector<int> res(length, 0);
        int sum = 0;
        for (int i=0;i<length;++i) {
            sum += record[i];
            res[i] = sum;
        }
        return res;
    }
};

// Another:

class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> res(length, 0);
        for (vector<int>& update : updates) {
            res[update[0]] += update[2];
            if (update[1]+1<length) res[update[1]+1] -= update[2];
        }
        for (int i=1;i<length;++i) {
            res[i] += res[i-1];
        }
        return res;
    }
};