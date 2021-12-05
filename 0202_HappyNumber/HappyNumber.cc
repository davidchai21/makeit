class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> s;
        while (n != 1) {
            if (s.find(n) != s.end()) return false;
            s.insert(n);
            n = helper(n);
        }
        return true;
    }
private:
    int helper(int n) {
        int res = 0;
        while (n) {
            int d = n%10;
            res += d*d;
            n /= 10;
        }
        return res;
    }
};

// slow fast:

class Solution {
public:
    bool isHappy(int n) {
        int slow = n, fast = helper(n);
        while (fast != 1 && slow != fast) {
            slow = helper(slow);
            fast = helper(helper(fast));
        }
        return fast == 1 ? true : false;
    }
private:
    int helper(int n) {
        int res = 0;
        while (n) {
            int d = n%10;
            res += d*d;
            n /= 10;
        }
        return res;
    }
};