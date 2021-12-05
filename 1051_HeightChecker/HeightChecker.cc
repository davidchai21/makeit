class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> b(heights.begin(), heights.end());
        sort(b.begin(), b.end());
        int count = 0;
        for (int i=0;i<b.size();++i) {
            if (b[i] != heights[i]) ++count;
        }
        return count;
    }
};

// Count sort:

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> b(101, 0);
        const int size = 100;
        for (int& k : heights) ++b[k];
        int res = 0;
        int index = 1;
        for (int& h : heights) {
            while (index <= size && !b[index]) ++index;
            if (index != h) ++res;
            --b[index];
        }
        return res;
    }
};