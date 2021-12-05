class Solution {
public:
    bool reorderedPowerOf2(int N) {
        string base = count(N);
        for (int i=0;i<31;++i) {
            if (count(1<<i).compare(base) == 0) return true;
        }
        return false;
    }
private:
    string count(int n) {
        array<int, 10> record;
        record.fill(0);
        while (n) {
            int d = n%10;
            n /= 10;
            ++record[d];
        }
        string res = "";
        for (int i=0;i<10;++i) {
            if (record[i]) res += to_string(i)+":"+to_string(record[i])+",";
        }
        return res;
    }
};