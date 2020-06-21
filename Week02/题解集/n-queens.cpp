#include<string.h>
#include<vector>
#include<iostream>
#include <algorithm>

using namespace std;

#define DEFAULT_CAPACITY 20

struct Queen{
    int x,y;//皇后在棋盘上的位置坐标
    Queen (int xx=0,int yy=0):x(xx),y(yy){};
    bool operator==(Queen const& q)const{
        return (x == q.x)
            || (y == q.y)
            || (x+y == q.x + q.y)//沿正对角线冲突 即左上-右下
            || (x-y == q.x - q.y);//沿副对角线冲突 即左下-右上
    }
    bool operator!=(Queen const& q)const{
        return !(*this == q);
    }
};

class Stack{
public:
    Queen* elem;
    int size;
Stack(){
    elem = new Queen[DEFAULT_CAPACITY];
    size = 0;
}
~Stack(){ delete []elem;}
int find(Queen const& e){
    for(int i=0;i<size;i++){
        if(e == elem[i])
            return i;
    }
    return -1;
}
//入栈：作为末尾元素插入
void push(Queen const& e){
    elem[size] = e;
    size++;
}
//出栈：等效于删除向量的最后一个元素
Queen pop(){
    size--;
    return  elem[size];
}
//取顶：直接返回向量的末元素
Queen& top(){
    return elem[size-1];
}

};

//根据皇后所在的列的位置，画出这一行的位置图
string getRowStr(int col,int n){
    string str;
    for(int i=0;i<col;i++){
        str += '.';
    }
    str += 'Q';
    for(int i=col+1;i<n;i++){
        str += '.';
    }
    return str;
}

class Solution {
public:
    vector<vector<string>> res;
    Stack queSta;
void dep(int n,Queen q){
    if(q.x >= n){
         if(queSta.size == n){
            printf("solOne 的大小等于n了\n");
            //把栈转成vector
            vector<string> oneRes;
            for(int i=0;i<queSta.size;i++){
                string rowStr = getRowStr(queSta.elem[i].y,n);
                oneRes.push_back(rowStr);
            }
            res.push_back(oneRes);
            printf("------------res当前的大小：%d\n",res.size());
            return;
        }
        return;
    }
     
    printf("当前行：%d\n",q.x);
    // col 遍历当前行所有位置
    for(int col=0;col<n;col++){
        printf("进入for循环，col=%d\n",col);
        q.y = col;
        //通过与已有的皇后作比较
        if( queSta.find(q) < 0){
            printf("皇后占位：（%d，%d）\n",q.x,q.y);
            queSta.push(q);
            q.x++;
            dep(n,q);//进入下一行
            /*
              回退条件
              遍历了当前行所有列都不行，说明上一行的皇后位置需要重新设置，回退当前到上一次
            */
            printf("row=%d ,回退\n",q.x);
            queSta.pop();
            q.x--;
        }
    }  
}

vector<vector<string>> solveNQueens(int n) {
    Queen q(0,0);
    dep(n,q);  
    return res;
}
         
};

int main(){
    Solution sol;
    int n = 5;
    vector<vector<string>> myres;
    myres = sol.solveNQueens(n);
    printf("------------myres当前的大小：%d\n",myres.size());
    for(int i=0;i<myres.size();i++){
        cout<<endl<<"第"<<i<<"种解决方案"<<endl;
        for(int j=0;j<myres[i].size();j++){
            cout<<myres[i][j]<<endl;
        }   
        cout<<endl<<"第"<<i<<"种解决方案完----"<<endl;
    }
}