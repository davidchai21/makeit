class Solution {
public:
    int minimumTimeRequired(vector<int>& jobs, int k) {
        int res = INT_MAX;
        int n = jobs.size();
        vector<int> task(k, 0);
        helper(jobs, 0, task, res);
        return res;
    }
private:
    void helper(vector<int>& jobs, int index, vector<int>& task, int& res) {
        if (index == jobs.size()) {
            res = min(res, *max_element(task.begin(), task.end()));
            return;
        }
        
        unordered_set<int> seen;
        for (int i=0;i<task.size();++i) {
            if (seen.find(task[i]) != seen.end()) continue;
            if (task[i] + jobs[index] > res) continue;
            seen.insert(task[i]);
            task[i] += jobs[index];
            helper(jobs, index+1, task, res);
            task[i] -= jobs[index];
        }
    }
};