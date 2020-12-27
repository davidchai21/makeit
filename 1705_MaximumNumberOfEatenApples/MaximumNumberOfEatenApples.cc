class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        int n = apples.size();
        priority_queue<pair<int,int>, vector<pair<int,int>>, com> q;
        int res = 0;
        int i=0;
        for (;i<n;++i) {
            if (apples[i]) {
                q.push(make_pair(apples[i], i+days[i]));
            }
            while (!q.empty() && q.top().second <= i) q.pop();
            if (!q.empty()) {
                pair<int,int> t = q.top();
                q.pop();
                --t.first;
                if (t.first) q.push(t);
                ++res;
            }
        }
        
        while (true) {
            while (!q.empty() && q.top().second <= i) q.pop();
            if (!q.empty()) {
                pair<int,int> t = q.top();
                q.pop();
                --t.first;
                if (t.first) q.push(t);
                ++res;
            } else break;
            ++i;
        }
        return res;
    }
private:
    struct com {
        bool operator() (pair<int,int> a, pair<int,int> b) {
            return a.second > b.second;
        }
    };
};