class Solution {
public:
    double myPow(double x, int n) {
        if (n ==0) return 1;
        int64_t ln = n;
        double result  = 1;
        if (ln < 0)
        {
            x = 1 / x;
            ln = -ln;
        }
        return pow(x, ln);
    }
    double pow(double x, int64_t n) {
        if (n == 1) return x;
        double  half = pow(x, n/2);
        if (n / 2 * 2 != n)
            return half * half * x;
        else
            return half * half;
    }
};
