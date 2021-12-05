/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        int len = 0;
        int res = 0;
        char* start = buf;
        do {
            len = read4(buf);
            int l = min(len, n);
            n -= l;
            buf += l;
            res += l;
        } while (len && n);
        *buf = 0;
        buf = start;
        return res;
    }
};