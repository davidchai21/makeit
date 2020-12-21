class Solution {
public:
    Solution(double radius, double x_center, double y_center) {
        r = radius;
        x = x_center;
        y = y_center;
    }
    
    vector<double> randPoint() {
        while (true) {
            double x1 = getRandom(r);
            double y1 = getRandom(r);
            if (x1*x1 + y1*y1 < r*r) {
                return vector {x1+x, y1+y};
            }
        }
    }
private:
    double r,x,y;
    double getRandom(double l) {
        int mark = rand()%2 ? 1 : -1;
        return ((double)rand()/(double)RAND_MAX)*l*mark;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */

class Solution {
public:
    Solution(double radius, double x_center, double y_center) {
        this->x = x_center;
        this->y = y_center;
        this->r = radius;
    }
    
    vector<double> randPoint() {
        while (true) {
            double corx = getRandom(r);
            double cory = getRandom(r);
            if (corx*corx + cory*cory < r*r) return {x+corx, y+cory};
        }
    }
private:
    double r,x,y;
    uniform_real_distribution<double> urd{0.0, 1.0};
    default_random_engine dre;
    double getRandom(double x) {
        int mark = rand()%2 ? 1 : -1;
        return urd(dre)*mark*x;
    } 
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */