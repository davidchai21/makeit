class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        int n = buildings.size();
        vector<Node*> time(2*n);
        vector<vector<int>> res;
        for (int i=0;i<n;++i) {
            time[2*i] = new Node(buildings[i][0], buildings[i][2], true);
            time[2*i+1] = new Node(buildings[i][1], buildings[i][2], false);
        }
        sort(time.begin(), time.end(), [](const Node* a, const Node* b){
            return a->point < b->point;
        });
        map<int, int> m;
        m[0] = 1;
        int curH = 0;
        int curP = -1;
        int index = 0;
        while (index < 2*n) {
            curP = time[index]->point;
            while (index < 2*n && curP == time[index]->point) {
                int h = time[index]->height;
                m[h] += time[index]->isStart ? 1 : -1;
                if (m[h] == 0) m.erase(h);
                ++index;
            }
            if (m.rbegin()->first != curH) {
                curH = m.rbegin()->first;
                res.push_back({curP, curH});
            }
        }
        return res;
    }
private:
    struct Node {
        int point = -1;
        int height = 0;
        bool isStart = false;
        
        Node(int p, int h, bool f): point(p), height(h), isStart(f) {}
    };
};