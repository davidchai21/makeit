class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if (newColor == image[sr][sc]) return image;
        int m = image.size();
        int n = image[0].size();
        helper(image, sr, sc, m, n, image[sr][sc], newColor);
        return image;
    }
private:
    void helper(vector<vector<int>>& image, int x, int y, int& m, int& n, int base, int newColor) {
        if (x<0 || y<0 || x>=m || y>=n || image[x][y] != base) return;
        image[x][y] = newColor;
        
        helper(image, x+1, y, m, n, base, newColor);
        helper(image, x-1, y, m, n, base, newColor);
        helper(image, x, y+1, m, n, base, newColor);
        helper(image, x, y-1, m, n, base, newColor);
    }
};