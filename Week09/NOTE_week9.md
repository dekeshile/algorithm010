**目录：**

- [第19课 | 高级动态规划](#第19课--高级动态规划)
  - [常见的 DP 题目和状态方程](#常见的-dp-题目和状态方程)
  - [高阶的 DP 问题](#高阶的-dp-问题)
- [第20课 | 字符串算法](#第20课--字符串算法)
  - [字符串基础知识和引申题目](#字符串基础知识和引申题目)
  - [高级字符串算法](#高级字符串算法)
    - [最长子串、子序列](#最长子串子序列)
    - [字符串 + 递归 or DP](#字符串--递归-or-dp)
    - [字符串匹配算法](#字符串匹配算法)
      - [Rabin-Karp 算法](#rabin-karp-算法)
      - [KMP 算法](#kmp-算法)

# 第19课 | 高级动态规划

## 常见的 DP 题目和状态方程

### 爬楼梯

**递推公式:**

![img](https://cdn.nlark.com/yuque/__latex/d3f59ab8dc65f2dae839892df87b0cd8.svg)

**进阶过程:**

从时间复杂度 ![img](https://cdn.nlark.com/yuque/__latex/c7cf1b9b9c957554447d062a3d1ab89c.svg) -> 时间复杂度 ![img](https://cdn.nlark.com/yuque/__latex/7ba55e7c64a9405a0b39a1107e90ca94.svg)

从空间复杂度 ![img](https://cdn.nlark.com/yuque/__latex/7ba55e7c64a9405a0b39a1107e90ca94.svg) -> 时间复杂度 ![img](https://cdn.nlark.com/yuque/__latex/5e079a28737d5dd019a3b8f6133ee55e.svg)



**1.时间复杂度![img](https://cdn.nlark.com/yuque/__latex/c7cf1b9b9c957554447d062a3d1ab89c.svg) - 傻递归**

存在大量重复计算

```python
def f(n):
    if n <= 1: return 1
    return f(n - 1) + f(n - 2)
```

**2.时间复杂度和空间复杂度都为![img](https://cdn.nlark.com/yuque/__latex/7ba55e7c64a9405a0b39a1107e90ca94.svg)   - 缓存，记忆化**

存储每次的计算结果，计算时判断是否被计算过，如果已经计算过就无需再计算

```python
def f(n):
    if n <= 1: return 1
    if n not in mem:
        mem[n] = f(n - 1) + f(n - 2)
    return mem[n]
```

**3.时间复杂度和空间复杂度都为![img](https://cdn.nlark.com/yuque/__latex/7ba55e7c64a9405a0b39a1107e90ca94.svg)   - 动态规划**

```python
def f(n):
    dp = [1] * (n + 1)
    for i in range(2, n + 1):
        dp[i] = dp[i - 1] + dp[i - 2]
    return dp[n]
```

**4.时间复杂度为 ![img](https://cdn.nlark.com/yuque/__latex/7ba55e7c64a9405a0b39a1107e90ca94.svg)，空间复杂度为 ![img](https://cdn.nlark.com/yuque/__latex/5e079a28737d5dd019a3b8f6133ee55e.svg)   - 动态规划**

当前状态只与保存的上一次状态有关

```python
def f(n):
    x, y = 1, 1 
    for i in range(1, n):
        y, x = x + y, y
    return y
```

总结如下图：

![图片.png](https://cdn.nlark.com/yuque/0/2020/png/1458680/1596957363848-6e05c4dd-69a3-46fe-81be-e99140e424c6.png)

### 不同路径

总结如下图：

![image.png](https://cdn.nlark.com/yuque/0/2020/png/1458680/1596960170005-e8e369ef-799e-4c27-90f1-3f012d406eec.png)

### 打家劫舍

dp[i]状态的定义：![img](https://cdn.nlark.com/yuque/__latex/73a3b5884ab76cbe898c147b624a489b.svg)

![img](https://cdn.nlark.com/yuque/__latex/dd94716fb392dee5932efab06b3acee9.svg)



dp[i][0]状态定义：![img](https://cdn.nlark.com/yuque/__latex/73a3b5884ab76cbe898c147b624a489b.svg)  且没偷 nums[i]

dp[i][1]状态定义：![img](https://cdn.nlark.com/yuque/__latex/73a3b5884ab76cbe898c147b624a489b.svg)  且偷了 nums[i]

![img](https://cdn.nlark.com/yuque/__latex/f84006b7b160d25319080f74aa6597fb.svg)

![img](https://cdn.nlark.com/yuque/__latex/466c4e681cc9886b7e43627a4cde557f.svg)



总结如下图：

![image.png](https://cdn.nlark.com/yuque/0/2020/png/1458680/1596960243039-5aaef6d0-6db5-4ade-9d19-2844ca2a5b32.png)



### 最小路径和

dp[i][j]状态的定义： ![img](https://cdn.nlark.com/yuque/__latex/eb51316ccf68065f4ed8ba2a7ebf1af2.svg)

![img](https://cdn.nlark.com/yuque/__latex/ff82a7e64eb2e7709e45889897dd7a87.svg)

### 股票买卖

状态转移图：

![image.png](https://cdn.nlark.com/yuque/0/2020/png/1458680/1596960556839-7e4d7f08-3d15-4b37-95c4-bfa2baf1da1f.png)

![img](https://cdn.nlark.com/yuque/__latex/c95fcb047ef7a60023151a21b57ff0c4.svg)

- i 为天数
- k 为最多交易次数
- [0,1] 为是否持有股票

总状态数： n * K * 2 种状态

```python
for 0 <= i < n:
 for 1 <= k <= K:
    for s in {0, 1}:
        dp[i][k][s] = max(buy, sell, rest)
```

![img](https://cdn.nlark.com/yuque/__latex/7cefda1cc04e43c64706c25848c253f9.svg)

 max( 选择 rest , 选择 sell )

解释：今天我没有持有股票，有两种可能： 

- \- 我昨天就没有持有，然后今天选择 rest，所以我今天还是没有持有； 
- \- 我昨天持有股票，但是今天我 sell 了，所以我今天没有持有股票了。

![img](https://cdn.nlark.com/yuque/__latex/5be38e76052220c29e89a79190d7d350.svg)

 max( 选择 rest , 选择 buy )

解释：今天我持有着股票，有两种可能： 

- \- 我昨天就持有着股票，然后今天选择 rest，所以我今天还持有着股票； 
- \- 我昨天本没有持有，但今天我选择 buy，所以今天我就持有股票了



**初始状态：**

**![img](https://cdn.nlark.com/yuque/__latex/16953757f6e66c074d5f21570e4a78aa.svg)**

**![img](https://cdn.nlark.com/yuque/__latex/2973322ba13510c0c676ff0de4c211c2.svg)**



**状态转移方程：**

**![img](https://cdn.nlark.com/yuque/__latex/7cefda1cc04e43c64706c25848c253f9.svg)**

**![img](https://cdn.nlark.com/yuque/__latex/5be38e76052220c29e89a79190d7d350.svg)**



## 高阶的 DP 问题

**复杂度来源**

1. 状态拥有更多维度（二维、三维、或者更多、甚至需要压缩） 
2. 状态方程更加复杂

**本质**：内功、逻辑思维、数学

### 爬楼梯问题改进

• 1、2、3 

• x1, x2, …, xm 步 

• 前后不能走相同的步伐

#### [746. 使用最小花费爬楼梯](https://leetcode-cn.com/problems/min-cost-climbing-stairs/)

> 数组的每个索引作为一个阶梯，第 `i`个阶梯对应着一个非负数的体力花费值 `cost[i]`(索引从0开始)。
>
> 每当你爬上一个阶梯你都要花费对应的体力花费值，然后你可以选择继续爬一个阶梯或者爬两个阶梯。
>
> 您需要找到达到楼层顶部的最低花费。在开始时，你可以选择从索引为 0 或 1 的元素作为初始阶梯。
>
> **示例 1:**
>
> **输入:** cost = [10, 15, 20]
>
> **输出:** 15
>
> **解释:** 最低花费是从cost[1]开始，然后走两步即可到阶梯顶，一共花费15。
>
> **示例 2:**
>
>  **输入:** cost = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
>
> **输出:** 6
>
> **解释:** 最低花费方式是从cost[0]开始，逐个经过那些1，跳过cost[3]，一共花费6。
>
> **注意：**
>
> 1. `cost` 的长度将会在 `[2, 1000]`。
>2. 每一个 `cost[i]` 将会是一个Integer类型，范围为 `[0, 999]`。

```c++
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size());
        dp[0] = cost[0];
        dp[1] = cost[1];
        for (int i = 2; i < cost.size(); i++) {
            dp[i] = min(dp[i - 2], dp[i - 1]) + cost[i];
        }
        return min(dp[cost.size() - 2], dp[cost.size() - 1]);
    }
};
```

### 编辑距离

• 如果 word1[i] 与 word2[j] 相同，显然 dp[i][j]=dp[i-1][j-1] 

• 如果 word1[i] 与 word2[j] 不同，那么 dp[i][j] 可以通过 

1. 在 dp[i-1][j-1] 的基础上做 replace 操作达到目的 
2. 在 dp[i-1][j] 的基础上做 insert 操作达到目的 
3. 在 dp[i][j-1] 的基础上做 delete 操作达到目的 

取三者最小情况即可



# 第20课 | 字符串算法

## 字符串基础知识和引申题目

### [709. 转换成小写字母](https://leetcode-cn.com/problems/to-lower-case/)

> 实现函数 ToLowerCase()，该函数接收一个字符串参数 str，并将该字符串中的大写字母转换成小写字母，之后返回新的字符串。
>
> **示例 1：**
>
> **输入:** "Hello"
>
> **输出:** "hello"
>
> **示例 2：**
>
> **输入:** "here"
>
> **输出:** "here"

```c++
/*
利用ASCII值大小写之间相差32的性质，遇到大写的字母，加上32就是相应的小写字母。
*/
class Solution {
public:
    string toLowerCase(string str) {
        int len = str.size();
        for(int i = 0; i < len; ++ i){
            if(str[i] <= 'Z' && str[i] >= 'A'){
                str[i] = str[i] + 32;
            }
        }
        return str;
    }
};
```

### [58. 最后一个单词的长度](https://leetcode-cn.com/problems/length-of-last-word/)

> 给定一个仅包含大小写字母和空格 `' '` 的字符串 `s`，返回其最后一个单词的长度。如果字符串从左向右滚动显示，那么最后一个单词就是最后出现的单词。
>
> 如果不存在最后一个单词，请返回 0 。
>
> **说明：**一个单词是指仅由字母组成、不包含任何空格字符的 **最大子字符串**。
>
> **示例:**
>
> **输入:** "Hello World"
>
> **输出:** 5

```c++
class Solution {
public:
    int lengthOfLastWord(string s) {
        int res = 0;
        for(int i = s.length()-1; i >=0 ; i--)
        {
            if(res != 0 && s[i] == ' ')  break;
            if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
                res++;
        }
        return res;
    }
};
```

### [771. 宝石与石头](https://leetcode-cn.com/problems/jewels-and-stones/)

>  给定字符串`J` 代表石头中宝石的类型，和字符串 `S`代表你拥有的石头。 `S` 中每个字符代表了一种你拥有的石头的类型，你想知道你拥有的石头中有多少是宝石。
>
> `J` 中的字母不重复，`J` 和 `S`中的所有字符都是字母。字母区分大小写，因此`"a"`和`"A"`是不同类型的石头。
>
> **示例 1:**
>
> **输入:** J = "aA", S = "aAAbbbb"
>
> **输出:** 3
>
> **示例 2:**
>
> **输入:** J = "z", S = "ZZ"
>
> **输出:** 0
>
> **注意:**	
>
> - `S` 和 `J` 最多含有50个字母。
>-  `J` 中的字符不重复。

```c++
class Solution {
public:
    int numJewelsInStones(string J, string S)
    {
        unordered_map<char, bool> mp;
        int sum = 0;
        for (auto j : J)
            mp[j] = 1;
        for (auto s : S)
            if (mp[s]) sum++;
        return sum;
    }
};
```

### [14. 最长公共前缀](https://leetcode-cn.com/problems/longest-common-prefix/)

> 编写一个函数来查找字符串数组中的最长公共前缀。
>
> 如果不存在公共前缀，返回空字符串 `""`。
>
> **示例 1:**
>
> **输入:** ["flower","flow","flight"]
>
> **输出:** "fl"
>
> **示例 2:**
>
> **输入:** ["dog","racecar","car"]
>
> **输出:** ""
>
> **解释:** 输入不存在公共前缀。
>
> **说明:**
>
> 所有输入只包含小写字母 `a-z` 。

```c++
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (!strs.size()) {
            return "";
        }
        string prefix = strs[0];
        int count = strs.size();
        for (int i = 1; i < count; ++i) {
            prefix = longestCommonPrefix(prefix, strs[i]);
            if (!prefix.size()) {
                break;
            }
        }
        return prefix;
    }

    string longestCommonPrefix(const string& str1, const string& str2) {
        int length = min(str1.size(), str2.size());
        int index = 0;
        while (index < length && str1[index] == str2[index]) {
            ++index;
        }
        return str1.substr(0, index);
    }
};
```

## 高级字符串算法

### 最长子串、子序列

#### 1. Longest common sequence（最长子序列） 

![img](https://cdn.nlark.com/yuque/__latex/75f0810eb3711808b7a0d6bbaa19cce0.svg)

![img](https://cdn.nlark.com/yuque/__latex/bbdfcf4fcfab5891c05c362c04b9813d.svg)

#### 2. Longest common substring (最长子串） 

![img](https://cdn.nlark.com/yuque/__latex/0e45016960b19ea7ff82d5d5d5144009.svg)

![img](https://cdn.nlark.com/yuque/__latex/b3bafcef93c081422082179afba95083.svg)

#### 3. Edit distance（编辑距离） 

1. 暴力 O(n^3) 
2. 中间向两边扩张法 O(n^2) 
3. 动态规划 

首先定义 P(i, j)：  

​			true s[i, j] 是回文串 

P(i, j) =

​            false s[i, j] 不是a回文串 

接下来 

​	P(i, j) = (P(i+1, j-1) && S[i] == S[j]) 

### 字符串 + 递归 or DP

1. 暴力递归 
2. 动态规划 

dp [i] [j] 代表 T 前 i 字符串可以由 s 前 j 字符串组成最多个数。 

所以动态方程： 

当 ![img](https://cdn.nlark.com/yuque/__latex/0f534adef0e6f0b3d40ecebc41d71eb6.svg)

当 ![img](https://cdn.nlark.com/yuque/__latex/a6842d17bf142286e9c1cbe4937542d5.svg)

### 字符串匹配算法

1. 暴力法（brute force） - O(mn) 
2. Rabin-Karp 算法 
3. KMP 算法

#### Rabin-Karp 算法

在朴素算法中，我们需要挨个比较所有字符，才知道目标字符串中是否包含子串。那么， 是否有别的方法可以用来判断目标字符串是否包含子串呢？ 

答案是肯定的，确实存在一种更快的方法。为了避免挨个字符对目标字符串和子串进行比较， 我们可以尝试一次性判断两者是否相等。因此，我们要一个好的哈希函数（hash function）。 通过哈希函数，我们可以算出子串的哈希值，然后将它和目标字符串中的子串的哈希值进行比较。 这个新方法在速度上比暴力法有显著提升。

**Rabin-Karp 算法的思想：**

1. 假设子串的长度为 M (pat)，目标字符串的长度为 N (txt) 
2. 计算子串的 hash 值 hash_pat 
3. 计算目标字符串txt中每个长度为 M 的子串的 hash 值（共需要计算 N-M+1次） 
4. 比较 hash 值：如果 hash 值不同，字符串必然不匹配; 如果 hash 值相同，

还需要使用朴素算法再次判断

```c++
public final static int D = 256;

public final static int Q = 9997;

static int RabinKarpSerach(String txt, String pat) {
     int M = pat.length();
     int N = txt.length();
     int i, j;
     int patHash = 0, txtHash = 0;
     for (i = 0; i < M; i++) {
        patHash = (D * patHash + pat.charAt(i)) % Q;
        txtHash = (D * txtHash + txt.charAt(i)) % Q;
     }
     int highestPow = 1; // pow(256, M-1)
     for (i = 0; i < M - 1; i++) 
     highestPow = (highestPow * D) % Q;
     for (i = 0; i <= N - M; i++) { // 枚举起点
        if (patHash == txtHash) {
            for (j = 0; j < M; j++) {
                if (txt.charAt(i + j) != pat.charAt(j))
                    break;
            }
        if (j == M)
            return i;
       }
     if (i < N - M) {
        txtHash = (D * (txtHash - txt.charAt(i) * highestPow) + txt.charAt(i + M)) % Q;
        if (txtHash < 0)
            txtHash += Q;
     }
  }
  return -1; 
}
```

#### KMP 算法

KMP算法（Knuth-Morris-Pratt）的思想就是，当子串与目标字符串不匹配时，其实你已经知道了前面已经匹配成功那 一部分的字符（包括子串与目标字符串）。

以阮一峰的文章为例，当空格与 D 不匹配时，你其实知道前面六个字符是“ABCDAB”。

KMP 算法的想法是，设法利用这个已知信息，不要把“搜索位置” 移回已经比较过的位置，继续把它向后移，这样就提高了效率。 

![image.png](https://cdn.nlark.com/yuque/0/2020/png/1458680/1596962397952-6fc1f2fa-2afa-4dbe-ba35-d9a909ff6aea.png)