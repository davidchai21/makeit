class Solution {
public:
    bool isPossible(vector<int>& target) {
        int n = target.size();
        if (n == 1) return target.back() == 1;
        
        long sum = 0L;
        priority_queue<int> pq;
        for (int& num : target) {
            pq.push(num);
            sum += num;
        }
        
        while (sum > n) {
            int m = pq.top();
            pq.pop();
            long r = sum - m;
            if (m <= r) return false;
            if (r == 1) m = 1;
            else {
                if (m%r) m %= r;
                else return false;
            }
            pq.push(m);
            sum = m+r;
        }
        return sum == n;
    }
};

// Another:

class Solution {
public:
    bool isPossible(vector<int>& target) {
        if (target.size() == 1) return target.back() == 1;
        
        long sum = accumulate(target.begin(), target.end(), 0L);
        priority_queue<int> pq(target.begin(), target.end());
        
        for (;;) {
            int m = pq.top();
            pq.pop();
            long r = sum - m;
            if (m == 1 || r == 1) return true;
            if (m <= r || m%r == 0) return false;
            m %= r;
            pq.push(m);
            sum = r+m;
        }
        return false;
    }
};