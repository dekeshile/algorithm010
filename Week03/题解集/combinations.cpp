/*
	     1  2  3  4
-----------------------------------------------
		 1                 2          3
	2      3    4       3    4        4 
 3   4     4            4 
*/
class Solution {
public:
    vector<vector<int>> res;
    int limit;
    int lastNum;
    vector<int> solOne;//背包，初始化为空

    void dep(int start){
        //递归深度终止，返回上一层
        if(solOne.size() == limit){
            res.push_back(solOne);
            return;
        }
        //for循环结束之后，也返回上一层
        for(int i=start;i<=lastNum;i++){
            //做选择，把元素 i 放进背包
            solOne.push_back(i);
            //往下一层递归
            dep(i+1);
            //回退，撤销选择，删除背包放进去的元素 i 
            solOne.pop_back();
        }
    } 
    vector<vector<int>> combine(int n, int k) {
        lastNum = n;
        limit = k;
	    dep(1);
        return res;
    }
};