// Binary Search:

class Solution {
public:
    bool isPerfectSquare(int num) {
        int left = 1;
        int right = num;
        while (left <= right) {
            int mid = left + (right-left)/2;
            if (num/mid == mid) return num%mid == 0;
            else if (num/mid > mid) left = mid+1;
            else right = mid-1;
        }
        return false;
    }
};

class Solution {
public:
    bool isPerfectSquare(int num) {
        for (int i=1;i <= num/i;++i) {
            if (i == num/i && num%i==0) return true;
        }
        return false;
    }
};

// newton's method: 

class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num < 2) return true;
        
        int x = num/2;
        while (x > num/x) {
            x = (x+num/x)/2;
        }
        return x*x == num;
    }
};

// Another: 

class Solution {
public:
    bool isPerfectSquare(int num) {
        int base = 1;
        while (num > 0) {
            num -= base;
            base += 2;
        }
        return !num;
    }
};