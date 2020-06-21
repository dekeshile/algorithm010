/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 #include<stdlib.h>
 #include<stdio.h>
 #define N 10000
 #define OFFSITE 5000

struct Node{
    int data;
    int num;
};
struct Node countFre[N];

int cmp ( const void *a , void *b){
        struct Node *na = ( struct Node *)a;
        struct Node *nb = ( struct Node *)b;
        return nb->num - na->num;
}

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize){
    //初始化countFre
      memset(countFre,0,sizeof(struct Node)*N);
      int index;
      for(int i=0;i<numsSize;i++){
          index = (nums[i]+ OFFSITE)%N;
          countFre[index].num++;
          countFre[index].data = nums[i];
      }
      //将countFre做紧凑
      int j=0;
      for(int i=0;i<N;i++){
          if(countFre[i].num != 0){
              countFre[j++] = countFre[i];
          }
      }
      qsort(countFre,j,sizeof(countFre[0]),&cmp);
      int* res = (int*)malloc(sizeof(int)*k);
      for(int i=0;i<k;i++){
          res[i] = countFre[i].data;
      }
      *returnSize = k;
      return res;
}