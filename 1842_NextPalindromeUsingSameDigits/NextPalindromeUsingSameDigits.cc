class Solution {
public:
    string nextPalindrome(string num) {
        if (num.size() == 1) return "";
        int size = num.size()/2;
        string base = num.substr(0, size);
        int left = size-1;
        while (left && base[left]<=base[left-1]) --left;
        if (!left) return "";
        int right = left--;
        while (right < size && base[right] > base[left]) ++right;
        swap(base[left++], base[--right]);
        sort(base.begin()+left, base.end());
        
        string tail = base;
        reverse(tail.begin(), tail.end());
        return base + (num.size()%2 ? string(1, num[size]) : "") + tail;
    }
};