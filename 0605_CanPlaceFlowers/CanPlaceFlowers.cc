class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if (!n) return true;
        int len = flowerbed.size();
        for (int i=0;i<len;++i) {
            if (!flowerbed[i] && (i==0 || !flowerbed[i-1]) && (i+1==len || !flowerbed[i+1])) {
                flowerbed[i++] = 1;
                if (!--n) return true;
            }
        }
        return false;
    }
};