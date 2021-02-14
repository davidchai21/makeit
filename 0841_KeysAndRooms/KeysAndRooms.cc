class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_set<int> visited;
        queue<int> q;
        q.push(0);
        visited.insert(0);
        while (!q.empty()) {
            int n = q.front();
            q.pop();
            for (int& k : rooms[n]) {
                if (visited.find(k) == visited.end()) {
                    q.push(k);
                    visited.insert(k);
                }
            }
        }
        return rooms.size() == visited.size();
    }
};

// DFS:

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_set<int> s;
        helper(rooms, s, 0);
        return s.size() == rooms.size();
    }
private:
    void helper(vector<vector<int>>& rooms, unordered_set<int>& s, int index) {
        if (s.find(index) != s.end()) return;
        s.insert(index);
        for (int& k : rooms[index]) {
            helper(rooms, s, k);
        }
    }
};