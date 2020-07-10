目录
- [第12课 | 动态规划](#第12课--动态规划)
  - [一、定义](#一定义)
  - [二、关键点](#二关键点)
  - [三、课堂实战例题](#三课堂实战例题)
    - [1.斐波拉契数列](#1斐波拉契数列)
    - [3.最长公共子序列](#3最长公共子序列)
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



### 3.最长公共子序列





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
- *f [i] [1]  = 0;*
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

