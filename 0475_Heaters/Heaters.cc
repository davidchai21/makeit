class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(), heaters.end());
        int res = 0;
        for (int& h : houses) {
            int index = lower_bound(heaters, h);
            int radius = abs(heaters[index]-h);
            if (index) radius = min(radius, h-heaters[index-1]);
            res = max(res, radius);
        }
        return res;
    }
private:
    int lower_bound(vector<int>& heater, int target) {
        int left = 0, right = heater.size()-1;
        while (left < right) {
            int mid = left+(right-left)/2;
            if (heater[mid] == target) return mid;
            else if (heater[mid] > target) right = mid;
            else left = mid+1;
        }
        return left;
    }
};

// Double sort:

class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        vector<int> dis(houses.size(), INT_MAX);
        for (int i=0, j=0; i<houses.size() && j<heaters.size();) {
            if (houses[i] <= heaters[j]) {
                dis[i] = heaters[j]-houses[i];
                ++i;
            } else ++j;
        }
        for (int i=houses.size()-1, j=heaters.size()-1; i>=0 && j>=0;) {
            if (houses[i] >= heaters[j]) {
                dis[i] = min(dis[i], houses[i]-heaters[j]);
                --i;
            } else --j;
        }
        return *max_element(dis.begin(), dis.end());
    }
};