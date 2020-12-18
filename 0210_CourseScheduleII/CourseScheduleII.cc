class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> res(numCourses);
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> record(numCourses, vector<int>());
        for (vector<int>& pre: prerequisites) {
            ++indegree[pre[0]];
            record[pre[1]].push_back(pre[0]);
        }
        queue<int> q;
        int n = 0;
        for (int i=0;i<numCourses;++i) {
            if (!indegree[i]) q.push(i);
        }
        while (!q.empty()) {
            int t = q.front();
            res[n++] = t;
            q.pop();
            for (int& course: record[t]) {
                --indegree[course];
                if (!indegree[course]) q.push(course);
            }
        }
        return n == numCourses ?  res : vector<int>();
    }
};