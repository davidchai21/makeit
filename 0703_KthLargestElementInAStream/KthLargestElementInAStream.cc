class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        _k = k;
        for (int& num : nums) {
            pq.push(num);
            if (pq.size() > k) pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        if (pq.size() > _k) pq.pop();
        return pq.top();
    }
private:
    int _k;
    priority_queue<int, vector<int>, greater<int>> pq; 
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */