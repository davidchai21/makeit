class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> visited(n+1, false);
        string res = "";
        while (k > 1) {
            int tail = dic[n-1-res.size()];
            int count = (k-1)/tail+1;
            int diff = (count-1)*tail;
            int digit = 1;
            for (int i=1;i<n+1 && count;++i) {
                if (!visited[i]) {
                    digit = i;
                    --count;
                }
            }
            visited[digit] = true;
            res.push_back('0'+digit);
            k -= diff;
        }
        for (int i=1;i<n+1;++i) {
            if (!visited[i]) {
                res.push_back(i+'0');
            }
        }
        return res;
    }
private:
    vector<int> dic = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
};