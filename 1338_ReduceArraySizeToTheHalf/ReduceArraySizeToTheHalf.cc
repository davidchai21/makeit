class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int> m;
        for (int& a : arr) ++m[a];
        priority_queue<int, vector<int>, less<int>> pq;
        for (auto it = m.begin(); it != m.end(); ++it) {
            pq.push(it->second);
        }
        int size = arr.size(), count = size, res = 0;
        while (count*2 > size) {
            count -= pq.top();
            pq.pop();
            ++res;
        }
        return res;
    }
};

// Bucket Sort:

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int maxCount = 0;
        unordered_map<int, int> m;
        for (int& a : arr) {
            maxCount = max(maxCount, ++m[a]);
        }
        vector<int> record(maxCount+1, 0);
        for (auto it = m.begin(); it != m.end(); ++it) {
            ++record[it->second];
        }
        
        int count = 0, res = 0, target = arr.size()/2;
        for (int i=maxCount; i>0; --i) {
            for (int j=0;j<record[i];++j) {
                count += i;
                ++res;
                if (count >= target) {
                    return res;
                }
            }
        }
        return res;
    }
};