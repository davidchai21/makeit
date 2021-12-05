class Solution {
public:
    int compress(vector<char>& chars) {
        int right = 0, left = 0;
        int n = chars.size();
        while (left < n) {
            int r = left+1;
            while (r < n && chars[r] == chars[left]) ++r;
            chars[right++] = chars[left];
            if (r > left+1) {
                string count = to_string(r-left);
                for (int i=0;i<count.size();++i) {
                    chars[right++] = count[i];
                }
            }
            left = r;
        }
        return right;
    }
};