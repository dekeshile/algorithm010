/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include<stdlib.h>

void swap(int* aa,int* bb){
    int temp = *aa;
    *aa = *bb;
    *bb = temp;
}

//p及其孩子中,值最小者的下标
int getMin(int a[],int n,int p)
{
    int lc = p*2 + 1 ;
    int rc = p*2 + 2 ;
    int _min,smaller;
    if(rc < n) //有左右孩子
    {
        smaller = a[lc] < a[rc] ? lc:rc;
        _min = a[smaller] < a[p] ? smaller:p;
    }else{
        if(lc < n)//只有左孩子
        {
             _min = a[lc] < a[p] ? lc:p;
        }else{//没有左右孩子
            _min = p;
        }
    }
    return _min;
}
//单个结点的下滤操作
int perDownFilter(int a[],int n,int i)
{
    int j;//i及其孩子中值最小者下标
    while( i != (j = getMin(a,n,i)))//当 i = j时，即下面不再需要调整
    {
        swap(&a[i],&a[j]);//交换两者，并继续考察下降后的i
        i = j;

    }
    return i; //返回下滤操作抵达的最深的终结位置(亦i亦j)
}

void createHeap(int a[],int n)
{
    int cnt =0;
    for(int i = (n-2)/2;i>=0;i-- )
    {
        perDownFilter(a,n,i);//下滤内部结点
    }
}

int getHeapTop(int a[],int* n){
    if(a == NULL || *n <= 0)
        return 0;
    int res = a[0];
    a[0] = a[*n-1];//将最后一个元素放到堆顶
    perDownFilter(a,*n-1,0);//重新调整堆
    *n = *n-1;
    return res;
}

int* getLeastNumbers(int* arr, int arrSize, int k, int* returnSize){
    int* res = (int*)malloc(sizeof(int)*k);
    createHeap(arr,arrSize);
    int* heapSize = &arrSize;

    for(int i=0;i<k;i++){
        res[i] = getHeapTop(arr,heapSize);
    }
    *returnSize = k;
    return res;
}