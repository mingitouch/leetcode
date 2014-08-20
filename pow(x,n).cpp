class Solution {
public:
    double pow(double x, int n) {
        if(n == 0)
        {
            return 1;
        }
        if(x == 1)
            return 1;
        if(x == -1)
        {
            if(n % 2 == 0)
                return 1;
            else
                return -1;
        }
        int exp = n;
        if(n < 0)
        {
            exp = n * (-1);
        }
        double result = 1;
        while(exp)
        {
            if((exp & 1) != 0)
            {
                result *= x;
            }
            x *= x;
            exp >>= 1;
        }
        if(n > 0)
            return result;
        else
            return 1.0 / result;
    }
};
