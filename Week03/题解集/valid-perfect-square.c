/* 由 【x的平方根】的二分递归方法改造方法一*/
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
bool isPerfectSquare(int num){
    int sqrtX = findSqrt(0,num,num);
    if( (long long)sqrtX*sqrtX == num)
        return true;
    else 
        return false;
}

/* 由 【x的平方根】的二分递归方法改造方法二*/
//递归版的二分查找
bool findSqrt(int left,int right,int x){
     int mid = (left+right)/2;
     if(left > right)
        return false;
     if((long long)mid*mid == x)
        return true;
     else if((long long)mid*mid < x)
        return findSqrt(mid+1,right,x);
     else
       return findSqrt(left,mid-1,x);
}
bool isPerfectSquare(int num){
    return findSqrt(0,num,num);
}