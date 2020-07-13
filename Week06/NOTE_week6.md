目录
- [第12课 | 动态规划](#第12课--动态规划)
  - [一、定义](#一定义)
  - [二、关键点](#二关键点)
  - [三、课堂实战例题](#三课堂实战例题)
    - [1.斐波拉契数列](#1斐波拉契数列)
    - [2.路径计数](#2路径计数)
      - [62. 不同路径](#62-不同路径)
      - [63. 不同路径 II](#63-不同路径-ii)
    - [3.最长公共子序列](#3最长公共子序列)
    - [4.总结](#4总结)
  - [四、课后实战题目](#四课后实战题目)
    - [121. 买卖股票的最佳时机](#121-买卖股票的最佳时机)
    - [309. 最佳买卖股票时机含冷冻期](#309-最佳买卖股票时机含冷冻期)

# 第12课 | 动态规划

## 一、定义

1.Wiki 定义： 

https://en.wikipedia.org/wiki/Dynamic_programming 

2.“Simplifying a complicated problem by breaking it down into simpler sub-problems”  (in a recursive manner) 

3.Divide & Conquer + Optimal substructure 

 分治 + 最优子结构

## 二、关键点

**动态规划** 和 **递归** 或者 **分治** 没有根本上的区别（关键看**有无最优的子结构**） 

- 共性：找到重复子问题

- 差异性：最优子结构、中途可以**淘汰**次优解



## 三、课堂实战例题

### 1.斐波拉契数列



### 2.路径计数

![diffpath1](https://cdn.jsdelivr.net/gh/dekeshile/mycloudimg@master/diffpath1.png)



![](https://cdn.jsdelivr.net/gh/dekeshile/mycloudimg@master/diffpath2.png)





#### [62. 不同路径](https://leetcode-cn.com/problems/unique-paths/)

> 一个机器人位于一个 *m x n* 网格的左上角 （起始点在下图中标记为“Start” ）。
>
> 机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。
>
> 问总共有多少条不同的路径？
>
> ![img](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/10/22/robot_maze.png)
>
> 例如，上图是一个7 x 3 的网格。有多少可能的路径？
>
> **示例 1:**
>
> ```
> 输入: m = 3, n = 2
> 输出: 3
> 解释:
> 从左上角开始，总共有 3 条路径可以到达右下角。
> 1. 向右 -> 向右 -> 向下
> 2. 向右 -> 向下 -> 向右
> 3. 向下 -> 向右 -> 向右
> ```
>
> **示例 2:**
>
> ```
> 输入: m = 7, n = 3
> 输出: 28
> ```
>
> **提示：**
>
> - 1 <= m, n <= 100
> - 题目数据保证答案小于等于 2 * 10 ^ 9

**解题思路**

这是一道动态规划的题目。大问题可以划分为小的子问题或者说规模更小的问题。我们把目光不仅仅是盯着终点，而是泛化到网格中的每一个格子。

因为题目规定了机器人每次只能向下或者向右移动一步，所以对每个格子来说，都是从其正上方的格子或者正左方的格子走过来的，那么其走法就是分别走到这两个格子目前累积的走法数相加。

定义 dp [i] [j] 表示终点为(i,j)时的不同路径个数

因此得到动态转移方程

​		dp [i] [j] = dp [i] [j-1] + dp [i-1] [j]   

**代码实现**

二维dp

```c++
#define N 110
class Solution {
public:
    int uniquePaths(int m, int n) {
        //dp[i][j] 表示终点为(i,j)时的不同路径个数
        int dp[N][N];
        //第一列初始化为 1 
        for(int i=0;i<n;i++) dp[i][0] = 1;
        //第一行初始化为 1
        for(int i=0;i<m;i++) dp[0][i] = 1;
        for(int i=1;i<n;i++) {
            for(int j=1;j<m;j++) {
                //每个格子等于其左和其上的格子的dp值相加
                dp[i][j] = dp[i][j-1] + dp[i-1][j];
            }
        }
        return dp[n-1][m-1];
    }
};
```

优化空间复杂度，使用一维dp

因为其实我们在计算过程中，每一行的dp只与上一行的dp相关，所以一维数组就够用了

```c++
#define N 110
class Solution {
public:
    int uniquePaths(int m, int n) {
        //每次只用保存一行的结果
        int dp[N];
        //二维dp第一行初始化为1
        for(int i=0;i<m;i++) dp[i] = 1;
        //对二维dp来说就是从第二行开始一行一行的从左至右dp
        for(int i=1;i<n;i++) {
            for(int j=1;j<m;j++) {
                /*
                   每个格子等于其左和其上的格子的dp值相加
                    这里的dp[j-1]就相当于当前格子的正上方的格子
                    原dp[j]相当于当前格子的左边的格子
                */
                dp[j] = dp[j] + dp[j-1];
            }
        }
        return dp[m-1];
    }
};
```



#### [63. 不同路径 II](https://leetcode-cn.com/problems/unique-paths-ii/)

> 一个机器人位于一个 *m x n* 网格的左上角 （起始点在下图中标记为“Start” ）。
>
> 机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。
>
> 现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？
>
> ![img](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/10/22/robot_maze.png)
>
> 网格中的障碍物和空位置分别用 `1` 和 `0` 来表示。
>
> **说明：***m* 和 *n* 的值均不超过 100。
>
> **示例 1:**
>
> ```c
> 输入:
> [
>   [0,0,0],
>   [0,1,0],
>   [0,0,0]
> ]
> 输出: 2
> 解释:
> 3x3 网格的正中间有一个障碍物。
> 从左上角到右下角一共有 2 条不同的路径：
> 1. 向右 -> 向右 -> 向下 -> 向下
> 2. 向下 -> 向下 -> 向右 -> 向右
> ```

**解题思路**

> 参考 [简单DP，🤷‍♀️必须秒懂！](https://leetcode-cn.com/problems/unique-paths-ii/solution/jian-dan-dpbi-xu-miao-dong-by-sweetiee/)

动态规划题。可以在【 [62. 不同路径](https://leetcode-cn.com/problems/unique-paths/) 】的二维dp实现方式上稍加改造。

同样时在二维数组中自顶向下的递推思路，且有核心状态转移方程  `dp[i,j] = dp[i−1,j] + dp[i,j−1]`

不同的是本题的网格中有障碍物，障碍是不可到达的，因此若 *(i,j)* 为障碍物，*dp[i] [j] = 0*

不管是初始时或者在递归计算过程中，只要当前格子为障碍物，不可达，则 *dp[i] [j] = 0*

**1、状态定义**：

*dp[i] [j]* 表示走到格子 *(i,j)* 的方法数。
**2、状态转移**：

如果网格  *(i,j)* 上有障碍物，则 *dp[i] [j]* 值为 0，表示走到该格子的方法数为 0；
否则网格  *(i,j)*  可以从网格 *(i−1,j)* 或者 网格 *(i,j−1)* 走过来，因此走到该格子的方法数为走到网格 *(i−1,j)* 和网格 *(i,j−1)* 的方法数之和，即 `dp[i,j]=dp[i−1,j]+dp[i,j−1]`

状态转移方程如下：

![image-20200713210912511](https://cdn.jsdelivr.net/gh/dekeshile/mycloudimg@master/image-20200713210912511.png)


**3、初始条件**

第 1 列的格子只有从其上边格子走过去这一种走法，因此初始化 *dp [ i ] [ 0 ]* 值为 1，存在障碍物时为 0；

第 1 行的格子只有从其左边格子走过去这一种走法，因此初始化 *dp [ 0 ] [ j ]* 值为 1，存在障碍物时为 0。

```c++
int dp[N][N] = {0};
//第一列初始化为 1 ,有障碍物则为0，且当前面有障碍物，直接退出，后面都为0
for(int i=0;i<n && obstacleGrid[i][0] == 0;i++) {
    dp[i][0] = 1;
}
//第一行初始化为 1,有障碍物则为0，且当前面有障碍物，直接退出，后面都为0
for(int i=0;i<m && obstacleGrid[0][i] == 0;i++) {
    dp[0][i] = 1;
}
```

**代码实现**

```C++
#define N 110
class Solution {
public:
   int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        if( n == 0 ) return 0;
        int m = obstacleGrid[0].size();
        //dp[i][j] 表示终点为(i,j)时的不同路径个数
        int dp[N][N] = {0};
        //第一列初始化为 1 ,有障碍物则为0，且当前面有障碍物，直接退出，后面都为0
        for(int i=0;i<n && obstacleGrid[i][0] == 0;i++) {
            dp[i][0] = 1;
        }
        //第一行初始化为 1,有障碍物则为0，且当前面有障碍物，直接退出，后面都为0
        for(int i=0;i<m && obstacleGrid[0][i] == 0;i++) {
            dp[0][i] = 1;
        }
        //从左至右从上至下遍历网格，填充dp
        for(int i=1;i<n;i++) {
          for(int j=1;j<m;j++) {
            dp[i][j] = obstacleGrid[i][j] == 0 ? (dp[i][j-1] + dp[i-1][j]):0;
          }
        }
        return dp[n-1][m-1];
    }
};
```







### 3.最长公共子序列

![lrc1](https://cdn.jsdelivr.net/gh/dekeshile/mycloudimg@master/lrc1.png)





#### [1143. 最长公共子序列](https://leetcode-cn.com/problems/longest-common-subsequence/)

> 给定两个字符串 `text1` 和 `text2`，返回这两个字符串的最长公共子序列的长度。
>
> 一个字符串的 *子序列* 是指这样一个新的字符串：它是由原字符串在不改变字符的相对顺序的情况下删除某些字符（也可以不删除任何字符）后组成的新字符串。
>  例如，"ace" 是 "abcde" 的子序列，但 "aec" 不是 "abcde" 的子序列。两个字符串的「公共子序列」是这两个字符串所共同拥有的子序列。
>
> 若这两个字符串没有公共子序列，则返回 0。
>
> **示例 1:**
>
> ```
> 输入：text1 = "abcde", text2 = "ace" 
> 输出：3  
> 解释：最长公共子序列是 "ace"，它的长度为 3。
> ```
>
> **示例 2:**
>
> ```
> 输入：text1 = "abc", text2 = "abc"
> 输出：3
> 解释：最长公共子序列是 "abc"，它的长度为 3。
> ```
>
> **示例 3:**
>
> ```
> 输入：text1 = "abc", text2 = "def"
> 输出：0
> 解释：两个字符串没有公共子序列，返回 0。
> ```
>
> **提示:**
>
> - `1 <= text1.length <= 1000`
> - `1 <= text2.length <= 1000`
> - 输入的字符串只含有小写英文字符。

**解题思路**

动态规划。

**1、状态定义**：


**2、状态转移**：



**3、初始条件**



**代码实现**

```C++
#define N 1010
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();//行
        int m = text2.length();//列
        int dp[N][N] = {0};
        for(int i=1;i<n+1;i++) {
            for(int j=1;j<m+1;j++) {
                if(text1[i-1] == text2[j-1] ){
                     dp[i][j] = dp[i-1][j-1] + 1;
                }else{
                     dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
                }
            }
        }
        return dp[n][m];
    }
};
```



### 4.总结

**动态规划关键点**

- 最优子结构 *opt[n] = best_of( opt[n-1], opt[n-2], …)*

- 储存中间状态：*opt[i]*

- 递推公式（美其名曰：状态转移方程或者 DP 方程）  

  ​	*Fib: opt[i] = opt[n-1] + opt[n-2]*

  ​	二维路径 *opt[i,j] = opt [i+1] [j] + opt [i] [j+1]*  (且判断a[i,j]是否空地）



**动态规划小结**

- 打破自己的思维惯性，形成机器思维 
- 理解复杂逻辑的关键 
- 也是职业进阶的要点要领



## 四、课后实战题目

### [121. 买卖股票的最佳时机](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/)

> 给定一个数组，它的第 *i* 个元素是一支给定股票第 *i* 天的价格。
>
> 如果你最多只允许完成一笔交易（即买入和卖出一支股票一次），设计一个算法来计算你所能获取的最大利润。
>
> 注意：你不能在买入股票前卖出股票。
>
> **示例 1:**
>
> ```
> 输入: [7,1,5,3,6,4]
> 输出: 5
> 解释: 在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
> 注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格；同时，你不能在买入前卖出股票。
> ```
>
> **示例 2:**
>
> ```
> 输入: [7,6,4,3,1]
> 输出: 0
> 解释: 在这种情况下, 没有交易完成, 所以最大利润为 0。
> ```

**解题思路**

先做的 【 [122. 买卖股票的最佳时机 II](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/) 】这题，所以刚开始看的时候还没看出来这两题有什么区别，后来仔细看才发现，这道题 【**只允许完成一笔交易**】，而 122 这题 为了获得最大利润 【**可以尽可能地完成更多的交易（多次买卖一支股票）**】。

回到本题，只允许完成一笔交易，使得利润最大，那就是一个后面的最大值减去一个前面的最小值的问题了。

具体是：

遍历一趟数组，记录数组当前最小值、利润最大值

- 当遍历到的值小于最小值时，更新最小值
- 当遍历到的值大于最小值时，用当前的值减去最小值得到当前利润，再用当前利润和最大利润比较，更新最大利润

最后返回最大利润

**复杂度分析**

一趟遍历 ,所以是 `O(n)`

**代码实现**

```c++
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min = INT_MAX;
        int maxProfit = 0;
        for(int i=0;i<prices.size();i++) {
            if(prices[i] < min)
                min = prices[i];
            else{
                if( prices[i] - min > maxProfit)
                    maxProfit = prices[i] - min;
            }
        }
        return maxProfit;
    }
};
```





### [309. 最佳买卖股票时机含冷冻期](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/)

> 给定一个整数数组，其中第 *i* 个元素代表了第 *i* 天的股票价格 。
>
> 设计一个算法计算出最大利润。在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票）:
>
> - 你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
> - 卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)。
>
> **示例:**
>
> ```
> 输入: [1,2,3,0,2]
> 输出: 3 
> 解释: 对应的交易状态为: [买入, 卖出, 冷冻期, 买入, 卖出]
> ```

**解题思路**

> 1.参考  [官方题解](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/solution/zui-jia-mai-mai-gu-piao-shi-ji-han-leng-dong-qi-4/) 

属于动态规划问题

1.为什么是动态规划的题目，和 【 [122. 买卖股票的最佳时机 II](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/) 】有什么区别和联系

2.这几道题的共同点，通用的模板

3.启发，以后遇到动态规划的题怎么解决

**举个栗子** ![](https://cdn.jsdelivr.net/gh/dekeshile/mycloudimg@master/lizi2.jpg) ![](https://cdn.jsdelivr.net/gh/dekeshile/mycloudimg@master/lizi1.jpg)![](https://cdn.jsdelivr.net/gh/dekeshile/mycloudimg@master/lizi4.jpg) ![](https://cdn.jsdelivr.net/gh/dekeshile/mycloudimg@master/lizi5.gif)



**具体落实到解题**

**给出定义**

- *f [i] [0] = haveOne*，第 *i* 天结束之后持有一支股票得到的收益 ( 第 *i* 天买入了股票或者第 *i-1* 天持有股票第 *i* 不做任何操作 )
- *f [i] [1] = cold*，第 *i* 天结束之后处于冷冻期得到的收益 ( 第 *i* 天卖出了股票 )
- *f [i] [2] = noStock* ，第 *i* 天结束之后不持有任何股票，且不处于冷冻期得到的收益 ( 卖出股票后的一天或前一天啥也没干 )

![image.png](https://pic.leetcode-cn.com/143bca8f4230f2ac50a47ef57bf3ce0e78fc21fc47e21b4294b87429689fcfab-image.png)

**状态转移**

- ***f [i] [0]*  从第 i-1 天转移**

  1.第 *i* 天不做任何操作，则继承第 *i-1* 天的状态  *f [i] [0] = f [i-1] [0]*

  2.第 *i* 天买入股票，那么第 *i-1*天就不能持有股票且不能处于冷冻期 ( 从 *f [i-1] [2]* 转移状态过来 ) ,  

  即此时  *f [i] [0] = f [i-1] [2] - prices[i]*

    取以上两种取最大值 `max( f [i-1] [0],f [i-1] [2] - prices[i] )`

- ***f [i] [1]* 从第 i-1 天转移**

  第 *i-1*天必须持有股票， 第 *i*天卖出股票后导致第 *i* 天后处于冷冻期

  `f [i] [1] = f [i-1] [0] + prices[i]`

- ***f [i] [2]*  从第 i-1 天转移**

  1.第 *i-1* 天不持有任何股票，处于冷冻期，那么第 *i* 天就是不持有股票且不处于冷冻期

  2.第 *i-1* 天 不持有股票且不处于冷冻期，第 *i* 天 继续 不持有股票且不处于冷冻期

  以上两种取最大值   `f [i] [2] = max ( f [i-1] [1],f [i-1] [2] )`

  

  ✅ 最终答案 `max ( f [n-1] [1],f [n-1] [2] )`  ( 最后一天手上即使持有股票，有没有任何意义，所以不算进来 )

  

**初始化边界条件** 

- *f [i] [0] = -prices[0]*
- *f [i] [1]  = 0*
- *f [i] [2]  = 0*

**代码实现**

```c++
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty())
            return 0;
        int n = prices.size();
        int haveOne = -prices[0];
        int cold = 0;
        int noStock = 0;
        for(int i=1;i<n;i++) {
            int new_haveOne = max(haveOne,noStock - prices[i]);
            int new_cold = haveOne + prices[i];
            int new_noStock = max(cold,noStock);

            haveOne = new_haveOne;
            cold  = new_cold;
            noStock = new_noStock;
        }
        return max(cold,noStock);
    }
};
```

