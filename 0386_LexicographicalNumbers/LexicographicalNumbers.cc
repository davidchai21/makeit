class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        for (int num=1;num<10;++num) {
            dfs(res, n, num);
        }
        return res;
    }
private:
    void dfs(vector<int>& res, const int n, int num) {
        if (num > n) return;
        res.push_back(num);
        
        for (int i=0;i<10;++i) {
            dfs(res, n, num*10+i);
        }
    }
};

// O(1) space:

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res(n);
        int num = 1;
        for (int i=0;i<n;++i) {
            res[i] = num;
            if (num*10 <= n) {
                num *= 10;
            } else {
                if (num == n) num /= 10;
                ++num;
                while (num%10 == 0) num /= 10;
            }
        }
        return res;
    }
};