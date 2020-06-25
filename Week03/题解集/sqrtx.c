/* 方法一*/
int mySqrt(int x){
    int i;
    long long next;
    for(i=0;i<=x;i++){
        next = (long long )(i+1)*(i+1);
        if( i*i <= x && next > x )
            break;
    }
    return i;
}

/* 方法二*/
/*
   sqrt(x) = e^( (1/2)*lnx )
*/
int mySqrt(int x){
    if(x == 0)
        return 0;
    int  sqrt1  = exp( 0.5 * log(x) );
    int sqrt2 = sqrt1 + 1;
    if( sqrt1*sqrt1 <= x && (long long) sqrt2*sqrt2 > x )
        return sqrt1;
    else 
        return sqrt2;
}

/* 方法三*/
/*
用二分查找 ,初始时范围为 [0,x]
注意结束条件
if（left > right）
    return right 
实际上是最后几步left和right已经很接近了。
前前一步，left1 + 1 = right1 ,mid1 = left1,而此时mid1*mid1 <= x,进入下一次调用left2 = left1 + 1 = right1
前一步，由上次之后，left2 = right1 ,mid2 = left2 = right1 , mid2*mid2 > x ,进入下一次调用 right3 = mid2 -1 
这步，发现 left2 > right3  ,返回结果实right3,而 right3 = mid2 - 1 =   left2 - 1 =  left1 = mid1

举个例子，求 8的平方根。
[0,8 ] 8/2 = 4 , 4*4 = 16 > 8    -> 
[0,3], 3/2 = 1,1*1 = 1<8         ->
[2,3],(2+3)/2 = 2, 2*2 = 4 < 8   ->
[3,3],(3+3)/2 = 3, 3*3 = 9 >8    ->
[3,2], 3>2 return 2;
*/
//递归版的二分查找
int findSqrt(int left,int right,int x){
     int mid = (left+right)/2;
     if(left > right)
        return right;
     if((long long)mid*mid <= x){
        return findSqrt(mid+1,right,x);
     }
     else
       return findSqrt(left,mid-1,x);
}
int mySqrt(int x){
    return findSqrt(0,x,x);
}