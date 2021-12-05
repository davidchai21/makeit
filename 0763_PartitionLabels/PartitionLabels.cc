class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> record(26, -1);
        int start = 0, end = 0;
        for (int i=0;i<S.size();++i) {
            record[S[i]-'a'] = i;
        }
        
        vector<int> res;
        for (int i=0;i<S.size();++i) {
            end = max(end, record[S[i]-'a']);
            if (end == i) {
                res.push_back(end-start+1);
                start = i+1;
            }
        }
        return res;
    }
};