class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int left = 0, right = 0, n = fruits.size();
        unordered_map<int, int> m;
        while (right < n) {
            ++m[fruits[right++]];
            if (m.size() > 2) {
                if (--m[fruits[left]] == 0) {
                    m.erase(fruits[left]);
                }
                ++left;
            }
        }
        return right-left;
    }
};