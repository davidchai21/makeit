class Solution {
public:
    Solution(vector<int>& w) {
        record.resize(w.size());
        record[0] = w[0];
        for (int i=1;i<w.size();++i) {
            record[i] = record[i-1]+w[i];
        }
    }
    
    int pickIndex() {
        int val = rand()%record.back();
        int left = 0, right = record.size()-1;
        while (left < right) {
            int mid = left + (right - left)/2;
            if (record[mid] > val) right = mid;
            else left = mid+1;
        }
        return left;
    }
private:
    vector<int> record;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */