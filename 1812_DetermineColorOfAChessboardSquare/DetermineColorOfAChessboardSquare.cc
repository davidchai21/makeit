class Solution {
public:
    bool squareIsWhite(string coordinates) {
        return (coordinates.front()-'a'+coordinates.back()-'1')&1;
    }
};