class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> st;
        for (int i=0;i<s.size();++i) {
            if (st.empty() || st.top().first != s[i]) {
                st.push(make_pair(s[i],1));
            } else ++st.top().second;
            if (st.top().second == k) st.pop();
        }
        string res = "";
        while (!st.empty()) {
            for (int i=0;i<st.top().second;++i) {
                res += st.top().first;
            }
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

// Another:

class Solution {
public:
    string removeDuplicates(string s, int k) {
        int index = 0;
        stack<int> count;
        for (int i=0;i<s.size();++i,++index) {
            s[index] = s[i];
            if (index==0 || s[index] != s[index-1]) {
                count.push(1);
            } else if (++count.top() == k) {
                count.pop();
                index -= k;
            }
        }
        return s.substr(0,index);
    }
};