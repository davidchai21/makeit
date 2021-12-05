class Solution {
public:
    int secondHighest(string s) {
        int first = -1, second = -1;
        for (char& c : s) {
            if (isdigit(c)) {
                int value = c-'0';
                if (first < value) {
                    second = first;
                    first = value;
                } else if (first == value) continue;
                else if (second < value) {
                    second = value;
                }
            }
        }
        return second;
    }
};