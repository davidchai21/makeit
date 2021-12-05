class Solution {
public:
    vector<string> generatePossibleNextMoves(string currentState) {
        vector<string> res;
        int n = currentState.size();
        for (int i=1;i<n;++i) {
            if (currentState[i] == '+' && currentState[i-1] == '+') {
                currentState[i] = currentState[i-1] = '-';
                res.push_back(currentState);
                currentState[i] = currentState[i-1] = '+';
            }
        }
        return res;
    }
};