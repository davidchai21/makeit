class Solution {
public:
    int thirdMax(vector<int>& nums) {
        vector<int> record(3,0);
        int count = 0;
        for (int &num : nums) {
            if (!count) {
                ++count;
                record[0] = num;
            } else if (count == 1 && record[0] != num) {
                if (num > record[0]) {
                    record[1] = record[0];
                    record[0] = num;
                } else {
                    record[1] = num;
                }
                ++count;
            } else if (count == 2 && record[0] != num && record[1] != num) {
                if (num > record[0]) {
                    record[2] = record[1];
                    record[1] = record[0];
                    record[0] = num;
                } else if (num < record[0] && num > record[1]) {
                    record[2] = record[1];
                    record[1] = num;
                } else if (num < record[1]) {
                    record[2] = num;
                }
                ++count;
            } else if (count == 3 && record[0] != num && record[1] != num && record[2] != num) {
                if (num > record[0]) {
                    record[2] = record[1];
                    record[1] = record[0];
                    record[0] = num;
                } else if (num < record[0] && num > record[1]) {
                    record[2] = record[1];
                    record[1] = num;
                } else if (num < record[1] && num > record[2]) {
                    record[2] = num;
                }
            }
        }
        return count == 3 ? record.back() : record.front();
    }
};

// Set:

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> s;
        for (int &num : nums) {
            s.insert(num);
            if (s.size() > 3) {
                s.erase(s.begin());
            }
        }
        return s.size() == 3 ? *s.begin() : *s.rbegin();
    }
};