class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, Comp> pq;
        for (vector<int>& c : classes) {
            pq.push(make_pair(c[0], c[1]));
        }
        while (extraStudents--) {
            pair<int,int> cur = pq.top();
            pq.pop();
            pq.push(make_pair(cur.first+1, cur.second+1));
        }
        double sum = 0.0;
        while (!pq.empty()) {
            pair<int,int> cur = pq.top();
            pq.pop();
            sum += (double)cur.first/cur.second;
        }
        return sum/classes.size();
    }
private:
    struct Comp {
        bool operator() (const pair<int,int>& a, const pair<int,int>& b) {
            return (double)(a.first+1)/(a.second+1)-(double)a.first/a.second < (double)(b.first+1)/(b.second+1)-(double)b.first/b.second;
        }
    };
};