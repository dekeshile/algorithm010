/*
    动态规划
    丑数因子只能包含 2，3，5，因此有丑数 = 某较小丑数 * 某丑数因子  
*/
int nthUglyNumber(int n){
    int *dp = (int*)malloc(sizeof(int)*n);
    dp[0] = 1;
    int a=0,b=0,c=0;
    int j=1;
    int min;
    int xa,xb,xc;
    while(j < n){
        xa = dp[a]*2;
        xb = dp[b]*3;
        xc = dp[c]*5;
        min = xa < xb ? (xa < xc ? xa: xc ) : ( xb < xc ? xb:xc);
        dp[j++] = min;

        if( min == xa)
            a++;
        if(min == xb)
            b++;
        if(min == xc)
            c++;
    }
    return dp[n-1];
}
