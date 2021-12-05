class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        if (n < 10) return n;
        string num = to_string(n);
        int index = 0, size = num.size();
        while (index < size-1 && num[index] <= num[index+1]) ++index;
        if (index == size-1) return n;
        
        for (int i=index+2;i<size;++i) num[i] = '9';
        while (index >=0 && num[index] > num[index+1]) {
            --num[index];
            num[index+1] = '9';
            --index;
        }
        return stoi(num);
    }
};