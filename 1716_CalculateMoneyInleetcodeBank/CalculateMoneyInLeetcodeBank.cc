class Solution {
public:
    int totalMoney(int n) {
        int week = n/7;
        int rest = n%7;
        return (week+7)*week/2*7 + (2*week+1+rest)*rest/2;
    }
};