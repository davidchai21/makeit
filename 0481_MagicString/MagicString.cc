class Solution {
public:
    int magicalString(int n) {
        if (n < 4) return 1;
        queue<int> q;
        q.push(2);
        int count = 3;
        int left = 0;
        int res = 1;
        int tail = 2;
        while (count < n) {
            if (!left) {
                left = q.front()-1;
                q.pop();
                tail = 3-tail;
                q.push(tail);
            } else {
                --left;
                q.push(tail);
            }
            if (tail == 1) ++res;
            ++count;
        }
        return res;
    }
};