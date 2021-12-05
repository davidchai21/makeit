class Solution {
public:
    bool judgePoint24(vector<int>& cards) {
        sort(cards.begin(), cards.end());
        do {
            if (helper(cards[0], cards[1], cards[2], cards.back())) return true;
        } while (next_permutation(cards.begin(), cards.end()));
        return false;
    }
private:
    const int target = 24;
    const double esp = 0.0001;
    
    bool helper(double a, double b, double c, double d) {
        if (helper(a+b, c, d) || helper(a-b, c, d) || helper(a*b, c, d) || helper(a/b, c, d)) return true;
        if (helper(a, b+c, d) || helper(a, b-c, d) || helper(a, b*c, d) || helper(a, b/c, d)) return true;
        if (helper(a, b, c+d) || helper(a, b, c-d) || helper(a, b, c*d) || helper(a, b, c/d)) return true;
        return false;
    }
    
    bool helper(double a, double b, double c) {
        if (helper(a+b, c) || helper(a-b, c) || helper(a*b, c) || helper(a/b, c)) return true;
        if (helper(a, b+c) || helper(a, b-c) || helper(a, b*c) || helper(a, b/c)) return true;
        return false;
    }
    
    bool helper(double a, double b) {
        if (fabs(a+b-target) <= esp || fabs(a-b-target) <= esp || fabs(a*b-target) <= esp || fabs(a/b-target) <= esp) return true;
        return false;
    }
};