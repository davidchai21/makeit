class Solution {
public:
    int badSensor(vector<int>& sensor1, vector<int>& sensor2) {
        int index = 0, n = sensor1.size();
        while (index < n && sensor1[index] == sensor2[index]) ++index;
        if (index >= n-1) return -1;
        while (index < n-1 && sensor1[index] == sensor2[index+1]) ++index;
        return index == n-1 ? 1 : 2;
    }
};