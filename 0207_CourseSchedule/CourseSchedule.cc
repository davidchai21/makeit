class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> res(numCourses, 0);
        vector<vector<int>> course(numCourses, vector<int>());
        for (vector<int>& pre: prerequisites) {
            ++res[pre[0]];
            course[pre[1]].push_back(pre[0]);
        }
        queue<int> q;
        int n=numCourses;
        for (int i=0;i<numCourses;++i) {
            if (!res[i]) q.push(i);
        }
        while (!q.empty()) {
            int k=q.front();
            q.pop();
            --n;
            for (int c: course[k]) {
                --res[c];
                if (!res[c]) q.push(c);
            }
        }
        return !n;
    }
};