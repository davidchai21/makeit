class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if (!n) return tasks.size();
        unordered_map<char, int> m;
        int maxNum = 0;
        for (char& c : tasks) {
            ++m[c];
            maxNum = max(maxNum, m[c]);
        }
        int res = (maxNum-1)*(n+1);
        for (auto it = m.begin(); it != m.end(); ++it) {
            if (maxNum == it->second) ++res;
        }
        return max(res, (int)tasks.size());
    }
};