class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> res;
        int n = asteroids.size();
        for (int & a : asteroids) {
            if (a > 0) res.push_back(a);
            else {
                if (res.empty() || res.back() < 0) res.push_back(a);
                else {
                    while (!res.empty() && res.back() > 0 && res.back() < -a) {
                        res.pop_back();
                    }
                    if (res.empty() || res.back() < 0) res.push_back(a);
                    else if (res.back() == -a) res.pop_back();
                }
            }
        }
        return res;
    }
};

// Another:

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> res;
        for (int i=0; i < asteroids.size(); ++i) {
            if (asteroids[i] > 0 || res.empty() || res.back() < 0) res.push_back(asteroids[i]);
            else if (res.back() <= -asteroids[i]) {
                if (res.back() < -asteroids[i]) --i;
                res.pop_back();
            }
        }
        return res;
    }
};