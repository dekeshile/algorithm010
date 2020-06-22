#include<math.h>

/*
    快速幂迭代版，时间复杂度O(logn)
    求 a^n
*/
double pow_iteration(double a,long long n)
{
    double pow = 1.0;
    double p = a;
    while(0 < n)
    {
        if(n&1)
          pow *= p;
        p *= p;
        n >>= 1;
    }
    return pow;
}

double myPow(double x, long long n){
    double res=1.0;
    long long cnt = n;
    if(n <0 )
        cnt = labs((long long)n);

    res = pow_iteration(x,cnt);

    if(n <0 )
        res = 1.0/res;
    return res;
}

