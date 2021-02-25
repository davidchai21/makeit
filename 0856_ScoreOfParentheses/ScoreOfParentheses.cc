class Solution {
public:
    int scoreOfParentheses(string S) {
        stack<int> st;
        for (char& c : S) {
            if (c == '(') st.push(0);
            else {
                int sum = 0;
                while (!st.empty() && st.top()) {
                    sum += st.top();
                    st.pop();
                }
                if (!st.empty()) st.pop();
                sum = max(sum*2, 1);
                st.push(sum);
            }
        }
        
        int res = 0;
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }
        return res;
    }
};

// O(1) Space:

class Solution {
public:
    int scoreOfParentheses(string S) {
        int level = 0;
        int res = 0;
        for (int i=0;i<S.size();++i) {
            if (S[i] == '(') ++level;
            else {
                --level;
                if (S[i-1]=='(') res += 1<<level;
            }
        }
        return res;
    }
};