class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        sort(points.begin(), points.end(), [](vector<int>& a, vector<int>& b){
            return a[0]*a[0]+a[1]*a[1] < b[0]*b[0]+b[1]*b[1];
        });
        points.resize(K);
        return points;
    }
};

// Priority queue:

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<vector<int>> res(K);
        priority_queue<vector<int>, vector<vector<int>>, Comparison> pq;
        for (vector<int>& point : points) {
            pq.push(point);
            if (pq.size() > K) pq.pop();
        }
        for (int i=0;i<K;++i) {
            res[i] = pq.top();
            pq.pop();
        }
        return res;
    }
private:
    struct Comparison {
        bool operator() (vector<int>& a, vector<int>& b) {
            return a[0]*a[0]+a[1]*a[1] < b[0]*b[0]+b[1]*b[1];
        }
    };
};

// Quick Select:

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        quickSelect(points, 0, points.size()-1, K);
        points.resize(K);
        return points;
    }
private:
    void quickSelect(vector<vector<int>>& points, int left, int right, const int& K) {
        int index = partition(points, left, right);
        if (index == K-1) return;
        else if (index < K-1) {
            quickSelect(points, index+1, right, K);
        } else {
            quickSelect(points, left, index-1, K);
        }
    }
    
    int partition(vector<vector<int>>& points, int left, int right) {
        int randomIndex = rand()%(right-left+1) + left;
        int pivot = getDis(points[randomIndex]);
        swap(points[randomIndex], points[right]);
        int target = left;
        for (;left<right;++left) {
            if (getDis(points[left]) < pivot) {
                swap(points[left], points[target++]);
            }
        }
        swap(points[right], points[target]);
        return target;
    }
    
    inline int getDis(vector<int>& point) {
        return point[0]*point[0]+point[1]*point[1];
    }
};