/*
    Stack自定义的栈直接用了【n皇后】问题的栈
    看了官方的题解，有更简单不需要使用栈的方法，待做-----
*/
#include<iterator>
#define DEFAULT_CAPACITY 100

class Stack{
public:
    int* elem;
    int size;
Stack(){
    elem = new int[DEFAULT_CAPACITY];
    size = 0;
}
~Stack(){ delete []elem;}
int find(int const& e){
    for(int i=0;i<size;i++){
        if(e == elem[i])
            return i;
    }
    return -1;
}
//入栈：作为末尾元素插入
void push(int const& e){
    elem[size] = e;
    size++;
}
//出栈：等效于删除向量的最后一个元素
int pop(){
    size--;
    return  elem[size];
}
//取顶：直接返回向量的末元素
int& top(){
    return elem[size-1];
}
};

class Solution {
public:
    vector<vector<int>> res;
    vector<int> ori_nums;
    Stack stackSol;
    int numsSize;

    void dep(){
        if(stackSol.size == numsSize){
            //把栈转成vector
            vector<int> vec;
            for(int i=0;i<stackSol.size;i++)
                vec.push_back(stackSol.elem[i]);
            res.push_back(vec);
            return;
        }
        for(int i=0;i<numsSize;i++){
            //剪枝
            if(  stackSol.find(ori_nums[i]) >= 0)
                continue;
            stackSol.push(ori_nums[i]);
            dep();
            stackSol.pop();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        ori_nums.assign(nums.begin(), nums.end());
        numsSize = nums.size();
        dep();
        return res;
    }
};