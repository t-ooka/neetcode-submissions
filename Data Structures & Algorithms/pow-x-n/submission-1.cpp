class Solution {
   private:
    double power(double base, long long exponent) {
        if (exponent == 0) {
            return 1.0;
        }

        double half = power(base, exponent / 2);

        if (exponent % 2 == 0) {
            return half * half;
        }

        return half * half * base;
    }

   public:
    double myPow(double x, int n) {
        long long exponent = n;

        if (exponent < 0) {
            x = 1.0 / x;
            exponent = -exponent;
        }

        return power(x, exponent);
    }
};
