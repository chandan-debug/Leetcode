class Solution {
public:
    double myPow(double x, int n) {
        long long a = abs((long long)n);  // Use long long to handle potential overflow
        double ans = 1.0;
        
        while (a > 0) {
            if (a % 2 == 1)
                ans *= x;
            x *= x;
            a /= 2;
        }
        
        return (n < 0) ? 1 / ans : ans;
    }
};
