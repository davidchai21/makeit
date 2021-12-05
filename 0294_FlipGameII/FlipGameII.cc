class Solution {
public:
    bool canWin(string currentState) {
        unordered_map<string, bool> m;
        return helper(currentState, m);
    }
private:
    bool helper(string& currentState, unordered_map<string, bool>& m) {
        if (m.find(currentState) != m.end()) return m[currentState];
        
        bool flag = false;
        for (int i=1;i<currentState.size();++i) {
            if (currentState[i]=='+' && currentState[i-1]=='+') {
                currentState[i] = currentState[i-1] = '-';
                if (!helper(currentState, m)) flag = true;
                currentState[i] = currentState[i-1] = '+';
            }
        }
        return m[currentState] = flag;
    }
};