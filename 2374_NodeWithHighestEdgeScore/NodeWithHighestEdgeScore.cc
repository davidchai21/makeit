class Solution {
public:
    int edgeScore(vector<int>& edges) {
        int n = edges.size();
        vector<long> record(n, 0);
        for (int i=0;i<n;++i) {
            record[edges[i]] += i;
        }
        int index = 0;
        long sum = 0;
        for (int i=0;i<n;++i) {
            if (sum < record[i]) {
                sum = record[i];
                index = i;
            }
        }
        return index;
    }
};