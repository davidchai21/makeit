// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        int row, col;
        do {
            row = rand7();
            col = rand7();
        } while ((row-1)*7+col > 40);
        return ((row-1)*7+col-1)%10+1;
    }
};