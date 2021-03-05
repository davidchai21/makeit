class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> res(num_people, 0);
        int base = num_people*(num_people+1)/2;
        int p2 = num_people*num_people;
        int k = 0;
        while (base*(k+1) + p2*(k+1)*k/2 <= candies) ++k;
        if (base*(k+1) + p2*(k+1)*k/2 > candies) --k;
        if (base <= candies) {
            for (int i=0;i<num_people;++i) {
                int t = (k+1)*(i+1) + k*(k+1)*num_people/2;
                candies -= t;
                res[i] = t;
            }
        }
        int index = 0;
        ++k;
        while (candies > 0) {
            int count = min(k*num_people+index+1, candies);
            candies -= count;
            res[index++] += count;
        }
        return res;
    }
};

// Simulation:

class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> res(num_people, 0);
        for (int i=0;candies>0;++i) {
            res[i%num_people] += min(candies, i+1);
            candies -= i+1;
        }
        return res;
    }
};