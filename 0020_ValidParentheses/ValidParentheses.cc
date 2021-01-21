class Solution {
public:
    bool isValid(string s) {
        vector<char> st;
        for (char& c : s) {
            if (helper(c)) st.push_back(c);
            else {
                if (st.empty()) return false;
                if (c==')'&&st.back()=='(' || c==']'&&st.back()=='[' || c=='}'&&st.back()=='{') st.pop_back();
                else return false;
            }
        }
        return st.empty();
    }
private:
    inline bool helper(char& c) {
        return c=='(' || c=='[' || c=='{';
    }
};