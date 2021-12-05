class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        Window* w1 = new Window();
        Window* w2 = new Window();
        int left = 0, right = 0;
        int res = 0;
        for (int i=0;i<A.size();++i) {
            w1->add(A[i]);
            w2->add(A[i]);
            
            while (w1->getSize() > K) w1->remove(A[left++]);
            while (w2->getSize() >= K) w2->remove(A[right++]);
            
            res += right-left;
        }
        return res;
    }
private:
    struct Window {
        unordered_map<int, int> count;
        int num;
        
        Window(): num(0) {}
        
        void add(int x) {
            if (++count[x] == 1) ++num;
        }
        
        void remove(int x) {
            if (--count[x] == 0) --num;
        }
        
        int getSize() {
            return num;
        }
    };
};