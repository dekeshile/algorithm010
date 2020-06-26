#include<string.h>
#include<vector>
#include<iostream>
#include <algorithm>
using namespace std;

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
    vector<Queen> queSta;

void dep(int n,Queen q){
    if(q.x >= n){
         if(queSta.size() == n){
            //把栈转成vector
            vector<string> oneRes;
            for(int i=0;i<queSta.size();i++){
                string rowStr = getRowStr(queSta[i].y,n);
                oneRes.push_back(rowStr);
            }
            res.push_back(oneRes);
            return;
        }
        return;
    }
     
    // col 遍历当前行所有位置
    for(int col=0;col<n;col++){
        q.y = col;
        //通过与已有的皇后作比较
        if(find(queSta.begin(),queSta.end(),q) == queSta.end()){
            queSta.push_back(q);
            q.x++;
            dep(n,q);//进入下一行
            /*
              回退条件
              遍历了当前行所有列都不行，说明上一行的皇后位置需要重新设置，回退当前到上一次
            */
            queSta.pop_back();
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