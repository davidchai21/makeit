class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        size_t res = candyType.size()/2;
        unordered_set<int> candy(candyType.begin(), candyType.end());
        return min(res, candy.size());
    }
};