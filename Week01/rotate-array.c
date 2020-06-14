void swap(int* a,int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void rotate(int* nums, int numsSize, int k){
    if(nums == NULL || numsSize <= 0 || k<=0)
        return;
    k = k%numsSize;
    int start = 0;
    int preVal,next,curr;
    int cnt=0;
    while(cnt < numsSize){
        curr = start;
        preVal = nums[start];
        do{
            next = (curr + k)%numsSize;
            swap(&nums[next],&preVal);
            curr = next;
            cnt++;
        }while(curr !=start);
        start++; //有环产生,前进一步
    }
}
