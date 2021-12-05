class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> left(n, n), right(n, n);
        left[0] = 1;
        for (int i=1;i<n;++i) {
            if (ratings[i] > ratings[i-1]) left[i] = left[i-1]+1;
            else left[i] = 1;
        }
        right.back() = 1;
        for (int i=n-2;i>=0;--i) {
            if (ratings[i] > ratings[i+1]) right[i] = right[i+1]+1;
            else right[i] = 1;
        }
        int res = 0;
        for (int i=0;i<n;++i) {
            res += max(left[i], right[i]);
        }
        return res;
    }
};

// Another:

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> record(n, 1);
        for (int i=1;i<n;++i) {
            if (ratings[i] > ratings[i-1]) record[i] = record[i-1]+1;
        }
        int res = record.back();
        for (int i=n-2;i>=0;--i) {
            if (ratings[i] > ratings[i+1]) record[i] = max(record[i], record[i+1]+1);
            res += record[i];
        }
        return res;
    }
};