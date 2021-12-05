class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        cost.push_back(0);
        vector<int> record(n+1, 0);
        record[0] = cost[0];
        record[1] = cost[1];
        for (int i=2;i<=n;++i) {
            record[i] = cost[i] + min(record[i-1], record[i-2]);
        }
        return record.back();
    }
};

// Another:

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        cost.push_back(0);
        int n = cost.size();
        for (int i=2;i<n;++i) {
            cost[i] += min(cost[i-1], cost[i-2]);
        }
        return cost.back();
    }
};