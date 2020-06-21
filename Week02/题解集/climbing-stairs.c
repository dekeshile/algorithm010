int climbStairs(int n){
    if(n <= 0)
        return 0;
    else if(n == 1)
        return 1;
    else if(n==2)
        return 2;
    else{
        int f1 = 1;
        int f2 = 2;
        int i = n-2;
        int temp;
        while(i--){
            temp = f2;
            f2 = f1 + f2;
            f1 = temp;
        }
        return f2;
    }
}