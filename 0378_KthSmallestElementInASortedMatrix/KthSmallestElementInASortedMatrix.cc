class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        priority_queue<int> pq;
        for (int i=0;i<n;++i) {
            for (int& num : matrix[i]) {
                pq.push(num);
                if (pq.size() > k) pq.pop();
            }
        }
        return pq.top();
    }
};

// pq 2:

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        priority_queue<pair<t, t>, vector<pair<t, t>>, Comp> pq;
        for (int i=0;i<n;++i) {
            pq.push(make_pair(matrix[i].begin(), matrix[i].end()));
        }
        while (--k) {
            pair<t, t> cur = pq.top();
            pq.pop();
            if (++cur.first != cur.second) {
                pq.push(cur);
            }
        }
        return *pq.top().first;
    }
private:
    typedef vector<int>::iterator t;
    
    struct Comp {
        bool operator() (const pair<t, t>& lhs, const pair<t, t>& rhs) {
            return *lhs.first > *rhs.first;
        }
    };
};