class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        int max_w = 0, max_h = 0;
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        
        int pre = 0;
        for (int& _h : horizontalCuts) {
            max_h = max(max_h, _h-pre);
            pre = _h;
        }
        max_h = max(max_h, h-pre);
        
        pre = 0;
        for (int& _w : verticalCuts) {
            max_w = max(_w-pre, max_w);
            pre = _w;
        }
        max_w = max(max_w, w-pre);
        
        return (long long) max_w*max_h%mod;
    }
private:
    const int mod = 1e9+7;
};