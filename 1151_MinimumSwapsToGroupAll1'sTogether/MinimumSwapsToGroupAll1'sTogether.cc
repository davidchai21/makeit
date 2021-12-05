class Solution {
public:
    int minSwaps(vector<int>& data) {
        int total = count(data.begin(), data.end(), 1);
        if (total < 2) return 0;
        
        int index = 0, n = data.size();
        int count = 0;
        for (;index<total;++index) {
            count += data[index];
        }
        int res = total-count;
        for (;index<n;++index) {
            count += data[index]-data[index-total];
            res = min(res, total-count);
        }
        return res;
    }
};

// Better:

class Solution {
public:
    int minSwaps(vector<int>& data) {
        int n = data.size();
        for (int i=1;i<n;++i) {
            data[i] += data[i-1];
        }
        if (!data.back()) return 0;
        
        int k = data.back();
        int res = k-data[k-1];
        for (int i=k;i<n;++i) {
            res = min(res, k-(data[i]-data[i-k]));
        }
        return res;
    }
};