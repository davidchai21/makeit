class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int left_x = max(A, E);
        int left_y = max(B, F);
        int right_x = min(C, G);
        int right_y = min(D, H);
        function<int(int,int,int,int)> f = [](const int a, const int b, const int c, const int d) {
            return (c-a)*(d-b);
        };
        
        int res = f(A,B,C,D)+f(E,F,G,H);
        if (left_x>=right_x || left_y>=right_y) return res;
        return res-f(left_x,left_y,right_x,right_y);
    }
};