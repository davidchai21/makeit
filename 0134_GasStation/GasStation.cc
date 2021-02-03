class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int sum = 0;
        int maxSum = 0;
        int index = n-1;
        for (int i=n-1;i>=0;--i) {
            sum += gas[i]-cost[i];
            if (sum >= maxSum) {
                index = i;
                maxSum = sum;
            }
        }
        return sum >= 0 ? index : -1;
    }
};

// Another:

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int curSum = 0;
        int totalSum = 0;
        int start = 0;
        for (int i=0;i<gas.size();++i) {
            curSum += gas[i]-cost[i];
            totalSum += gas[i]-cost[i];
            if (curSum < 0) {
                curSum = 0;
                start = i+1;
            }
        }
        return totalSum >=0 ? start : -1;
    }
};