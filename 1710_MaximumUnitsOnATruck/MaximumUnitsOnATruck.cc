class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [](vector<int>& a, vector<int>& b){
            return a[1] > b[1];
        });
        int res = 0;
        int count = 0;
        for (int i=0;i<boxTypes.size();++i) {
            for (int j=0;j<boxTypes[i][0];++j) {
                res += boxTypes[i][1];
                if (++count == truckSize) return res;
            }
        }
        return res;
    }
};