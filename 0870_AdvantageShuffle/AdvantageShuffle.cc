class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        map<int, int> m;
        for (int& a : A) ++m[a];
        for (int i=0;i<B.size();++i) {
            auto it = m.lower_bound(B[i]);
            if (it != m.end() && it->first == B[i]) ++it;
            if (it == m.end()) {
                it = m.begin();
                --it->second;
                A[i] = it->first;
                if (!it->second) m.erase(it);
            } else {
                --it->second;
                A[i] = it->first;
                if (!it->second) m.erase(it);
            }
        }
        return A;
    }
};

// Multi-set:

class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        multiset<int> s(A.begin(), A.end());
        for (int i=0;i<B.size();++i) {
            auto it = s.upper_bound(B[i]);
            if (it == s.end()) {
                it = s.begin();
            }
            A[i] = *it;
            s.erase(it);
        }
        return A;
    }
};