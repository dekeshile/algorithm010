**目录**
- [第9课 | 深度优先搜索和广度优先搜索](#第9课--深度优先搜索和广度优先搜索)
  - [知识点](#知识点)
  - [实战题目](#实战题目)
      - [433. 最小基因变化](#433-最小基因变化)
      - [127. 单词接龙](#127-单词接龙)
      - [529. 扫雷游戏](#529-扫雷游戏)
      - [126. 单词接龙 II](#126-单词接龙-ii)
- [第10课 |  贪心算法](#第10课--贪心算法)
  - [知识点](#知识点-1)
  - [实战题目](#实战题目-1)
      - [860. 柠檬水找零](#860-柠檬水找零)
      - [515. 在每个树行中找最大值](#515-在每个树行中找最大值)
      - [322. 零钱兑换](#322-零钱兑换)
- [第11课 | 二分查找](#第11课--二分查找)
  - [知识点](#知识点-2)
  - [实战题目](#实战题目-2)
      - [153. 寻找旋转排序数组中的最小值](#153-寻找旋转排序数组中的最小值)
      - [33. 搜索旋转排序数组](#33-搜索旋转排序数组)
      - [74. 搜索二维矩阵](#74-搜索二维矩阵)

# 第9课 | 深度优先搜索和广度优先搜索

## 知识点

**遍历顺序**

<img src="https://cdn.jsdelivr.net/gh/dekeshile/mycloudimg@master/image-20200706003554228.png" alt="image-20200706003554228" style="zoom:50%;" />

**DFS 代码 - 递归写法**

```python
visited = set() 
def dfs(node, visited): 
if node in visited: # terminator 
# already visited 
return 
 visited.add(node) 
# process current node here. 
...
for next_node in node.children(): 
 if not next_node in visited: 
 dfs(next_node, visited)
```

**DFS 代码 - 非递归写法**

```python

def DFS(self, tree): 
if tree.root is None: 
 return [] 
 visited, stack = [], [tree.root] 
while stack: 
 node = stack.pop() 
 visited.add(node) 
 process (node) 
 nodes = generate_related_nodes(node) 
 stack.push(nodes) 
# other processing work 
...
```

**BFS 代码 **

```python
def BFS(graph, start, end): 
 queue = [] 
 queue.append([start]) 
 visited.add(start) 
while queue: 
 node = queue.pop() 
 visited.add(node) 
 process(node) 
 nodes = generate_related_nodes(node) 
 queue.push(nodes)
```



## 实战题目

#### [433. 最小基因变化](https://leetcode-cn.com/problems/minimum-genetic-mutation/)

> 一条基因序列由一个带有8个字符的字符串表示，其中每个字符都属于 `"A"`, `"C"`, `"G"`, `"T"`中的任意一个。
>
> 假设我们要调查一个基因序列的变化。**一次**基因变化意味着这个基因序列中的**一个**字符发生了变化。
>
> 例如，基因序列由`"AACCGGTT"` 变化至 `"AACCGGTA" `即发生了一次基因变化。
>
> 与此同时，每一次基因变化的结果，都需要是一个合法的基因串，即该结果属于一个基因库。
>
> 现在给定3个参数 — start, end, bank，分别代表起始基因序列，目标基因序列及基因库，请找出能够使起始基因序列变化为目标基因序列所需的最少变化次数。如果无法实现目标变化，请返回 -1。
>
> **注意:**
>
> 1. 起始基因序列默认是合法的，但是它并不一定会出现在基因库中。
> 2. 所有的目标基因序列必须是合法的。
> 3. 假定起始基因序列与目标基因序列是不一样的。
>
> **示例 1:**
>
> ```
> start: "AACCGGTT"
> end:   "AACCGGTA"
> bank: ["AACCGGTA"]
> 返回值: 1
> ```
>
> **示例 2:**
>
> ```
> start: "AACCGGTT"
> end:   "AAACGGTA"
> bank: ["AACCGGTA", "AACCGCTA", "AAACGGTA"]
> 返回值: 2
> ```
>
> **示例 3:**
>
> ```
> start: "AAAAACCC"
> end:   "AACCCCCC"
> bank: ["AAAACCCC", "AAACCCCC", "AACCCCCC"]
> 返回值: 3
> ```

**解题思路**



**代码实现**

```c++
/*
注意：每一次基因变化的结果，都需要是一个合法的基因串，即该结果属于一个基因库。
*/
#include<queue>
#include<map>
using namespace std;
class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
      map<string, string> mymap;
      for(int i=0;i<bank.size();i++)
            mymap.insert(pair<string,string>(bank[i],bank[i]));
       //目标基因序列都不合法
      if(mymap.find(end) == mymap.end())
            return -1;
      char basic[] = {'A','C','G','T'};
      int nums = 0;
      queue<string> options;
      options.push(start);
      while(!options.empty()){
        //遍历所有备选基因串
        nums++;
        for(int k=options.size();k >0 ;k--) {
            string top = options.front();
            options.pop();
            //改变备选基因串的每一个字符，看是否与目标基因串相等或是否合法
            for(int i=0;i<top.length();i++) {
                char temp = top[i];
                for( int j = 0;j < 4 ;j++ ) {
                    top[i] = basic[j];
                    if(top == end)
                        return nums;
                    //是一个合法的基因串
                    if(   mymap.find(top) !=  mymap.end() ){
                        options.push(top);
                        mymap.erase(top);
                    }
                }
                top[i] = temp;
            }
        }
      }
     return -1;
    }
};
```



#### [127. 单词接龙](https://leetcode-cn.com/problems/word-ladder/)

> 给定两个单词（*beginWord* 和 *endWord*）和一个字典，找到从 *beginWord* 到 *endWord* 的最短转换序列的长度。转换需遵循如下规则：
>
> 1. 每次转换只能改变一个字母。
> 2. 转换过程中的中间单词必须是字典中的单词。
>
> **说明:**
>
> - 如果不存在这样的转换序列，返回 0。
> - 所有单词具有相同的长度。
> - 所有单词只由小写字母组成。
> - 字典中不存在重复的单词。
> - 你可以假设 *beginWord* 和 *endWord* 是非空的，且二者不相同。
>
> **示例 1:**
>
> ```
> 输入:
> beginWord = "hit",
> endWord = "cog",
> wordList = ["hot","dot","dog","lot","log","cog"]
> 
> 输出: 5
> 
> 解释: 一个最短转换序列是 "hit" -> "hot" -> "dot" -> "dog" -> "cog",
>      返回它的长度 5。
> ```
>
> **示例 2:**
>
> ```
> 输入:
> beginWord = "hit"
> endWord = "cog"
> wordList = ["hot","dot","dog","lot","log"]
> 
> 输出: 0
> 
> 解释: endWord "cog" 不在字典中，所以无法进行转换。
> ```

**解题思路 1 ** (暴力，不推荐)

先做的  [433. 最小基因变化](https://leetcode-cn.com/problems/minimum-genetic-mutation/)  这题，所以乍一看，和这题感觉几乎一样，只不过是这题每次换要换26个字母，而不是那题原来的4个字母，只要测试用例不是很为难人。。。应该可以过吧，于是说干就干。。。

**代码实现 1**

```c++
/*
注意：每一次基因变化的结果，都需要是一个合法的基因串，即该结果属于一个基因库。
*/
#include<queue>
#include<map>
using namespace std;
class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
      map<string, string> mymap;
      for(int i=0;i<bank.size();i++)
            mymap.insert(pair<string,string>(bank[i],bank[i]));
       //目标基因序列都不合法
      if(mymap.find(end) == mymap.end())
            return -1;
      char basic[] = {'A','C','G','T'};
      int nums = 0;
      queue<string> options;
      options.push(start);
      while(!options.empty()){
        //遍历所有备选基因串
        nums++;
        for(int k=options.size();k >0 ;k--) {
            string top = options.front();
            options.pop();
            //改变备选基因串的每一个字符，看是否与目标基因串相等或是否合法
            for(int i=0;i<top.length();i++) {
                char temp = top[i];
                for( int j = 0;j < 4 ;j++ ) {
                    top[i] = basic[j];
                    if(top == end)
                        return nums;
                    //是一个合法的基因串
                    if(   mymap.find(top) !=  mymap.end() ){
                        options.push(top);
                        mymap.erase(top);
                    }
                }
                top[i] = temp;
            }
        }
      }
     return -1;
    }
};
```

**解题思路 2  (图)**

参考了 【[官方题解](https://leetcode-cn.com/problems/word-ladder/solution/dan-ci-jie-long-by-leetcode/)】，有了这个图就好说了

<img src="https://cdn.jsdelivr.net/gh/dekeshile/mycloudimg@master/Word_Ladder_2.png" alt="Word_Ladder_2" style="zoom: 67%;" />

核心思想，把只相差一个字母的单词(包括start和字典中的所有单词)用线连在一起，就构成了一张图

那么要求从start到end的最小变换，就是求start到end的最短路径

当然这是一个无权图，还用不着迪杰斯特拉之类的最短路径算法。直接用层次遍历的方法，记录从start到end的层次即是最短路径。

**实现细节**

1.怎么知道两个单词只相差一个字母，怎么找到自己的下一个单词

2.如何记录层次也即最短序列长度

3.既然是图，怎样防止重复遍历到结点

**代码实现 2 **

```c++
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        wordList.push_back(beginWord);
        map<string,vector<string>> wordMap;
        //标记该单词是否被访问过，防止出现环
        map<string,int> visited;
        //对所有单词预处理，以单词的通配符为hash的key，对应的value为具有这个通配符的形式的单词集合
        for(int i=0;i<wordList.size();i++){
            //初始化visited
            visited.insert(pair<string,int>(wordList[i],0));
             string tempWord = wordList[i];
            for(int j=0;j<tempWord.length();j++){
                char temp = tempWord[j];
                tempWord[j] = '*';
                wordMap[tempWord].push_back(wordList[i]);
                tempWord[j] = temp;
             }
        }
        queue<string> que;
        que.push(beginWord);
        int nums = 1;
        while(!que.empty()){
            nums++;
            //遍历每个备选单词
            for(int i = que.size();i >0;i--){
                 string top = que.front();
                 string oldTop = top;
                 que.pop();
                 //遍历每个单词的所有通配形式
                 for(int k=0;k<top.length();k++) {
                    char temp = top[k];
                    top[k] = '*';
                     //遍历每个单词与它只相差一个字母的所有单词
                    for(int j=0;j<wordMap[top].size();j++){
                        string word = wordMap[top][j];
                        if( word == endWord )
                            return nums;
                        if(word != oldTop && visited[word] == 0){
                            que.push(wordMap[top][j]);
                            visited[word] =1;
                        }
                    }
                    top[k] = temp;
            } 
         }
        }
        return 0;
    }
};
```



还可以优化的地方，map用hash



#### [529. 扫雷游戏](https://leetcode-cn.com/problems/minesweeper/)

> 让我们一起来玩扫雷游戏！
>
> 给定一个代表游戏板的二维字符矩阵。 **'M'** 代表一个**未挖出的**地雷，**'E'** 代表一个**未挖出的**空方块，**'B'** 代表没有相邻（上，下，左，右，和所有4个对角线）地雷的**已挖出的**空白方块，**数字**（'1' 到 '8'）表示有多少地雷与这块**已挖出的**方块相邻，**'X'** 则表示一个**已挖出的**地雷。
>
> 现在给出在所有**未挖出的**方块中（'M'或者'E'）的下一个点击位置（行和列索引），根据以下规则，返回相应位置被点击后对应的面板：
>
> 1. 如果一个地雷（'M'）被挖出，游戏就结束了- 把它改为 **'X'**。
> 2. 如果一个**没有相邻地雷**的空方块（'E'）被挖出，修改它为（'B'），并且所有和其相邻的方块都应该被递归地揭露。
> 3. 如果一个**至少与一个地雷相邻**的空方块（'E'）被挖出，修改它为数字（'1'到'8'），表示相邻地雷的数量。
> 4. 如果在此次点击中，若无更多方块可被揭露，则返回面板。
>
> **示例 1：**
>
> ```
> 输入: 
> 
> [['E', 'E', 'E', 'E', 'E'],
>  ['E', 'E', 'M', 'E', 'E'],
>  ['E', 'E', 'E', 'E', 'E'],
>  ['E', 'E', 'E', 'E', 'E']]
> 
> Click : [3,0]
> 
> 输出: 
> 
> [['B', '1', 'E', '1', 'B'],
>  ['B', '1', 'M', '1', 'B'],
>  ['B', '1', '1', '1', 'B'],
>  ['B', 'B', 'B', 'B', 'B']]
> ```
>
> 解释:
>
> <img src="https://cdn.jsdelivr.net/gh/dekeshile/mycloudimg@master/minesweeper_example_1.png" alt="img" style="zoom:50%;" />
>
> **示例 2：**
>
> ```
> 输入: 
> 
> [['B', '1', 'E', '1', 'B'],
>  ['B', '1', 'M', '1', 'B'],
>  ['B', '1', '1', '1', 'B'],
>  ['B', 'B', 'B', 'B', 'B']]
> 
> Click : [1,2]
> 
> 输出: 
> 
> [['B', '1', 'E', '1', 'B'],
>  ['B', '1', 'X', '1', 'B'],
>  ['B', '1', '1', '1', 'B'],
>  ['B', 'B', 'B', 'B', 'B']]
> ```
>
>  解释:<img src="https://cdn.jsdelivr.net/gh/dekeshile/mycloudimg@master/minesweeper_example_2.png" alt="img" style="zoom:50%;" />
>
> **注意：**
>
> 1. 输入矩阵的宽和高的范围为 [1,50]。
> 2. 点击的位置只能是未被挖出的方块 ('M' 或者 'E')，这也意味着面板至少包含一个可点击的方块。
> 3. 输入面板不会是游戏结束的状态（即有地雷已被挖出）。
> 4. 简单起见，未提及的规则在这个问题中可被忽略。例如，当游戏结束时你不需要挖出所有地雷，考虑所有你可能赢得游戏或标记方块的情况。

**解题思路**

判断方向，走方向可以借鉴之前做的  [874. 模拟行走机器人](https://leetcode-cn.com/problems/walking-robot-simulation/)  ，这里有8个方向，就用大小为8的两个数组x,y分别表示往8个方向分别走时，坐标x,y要怎么变化。

> 如果一个**没有相邻地雷**的空方块（'E'）被挖出，修改它为（'B'），并且所有和其相邻的方块都应该被递归地揭露

从这句话就可以看出我们应该从给定的坐标点开始层层向外扩展，去改变每一个格子的状态，所以可以用广度优先搜索去进行遍历。

另外一个问题是当前遍历到的格子周围没有地雷，如果把这些周围的格子标记成了‘’B’，但是后面更外一层会发现这些周围的格子的更外层是有地雷的，这怎么办？

其实我们遍历当前格子周围的格子发现没有地雷时，可以暂且标记为‘B’,然后将这些格子入队列，当我们下一次再从队列中取出这些格子时，是会去遍历其周围的格子的，这时候其周围的格子就包括了刚才所说的更外一层的格子，当这更外一层有地雷时，这个格子的状态也会被再次更改了，所以是一个慢慢发现的过程。

**代码实现**

```c++
/*
用广度优先搜索 -> 队列
需要判断每个结点的上，下，左，右，和所有4个对角线这个8点是否是地雷
前面入队的没有发现周围有地雷，有可能在后面的时候发现了，所以后面还会进行更新
*/
#define valid(x,y,m,n) ( x >= 0 && x < m && y>=0 && y< n )
class Solution {
public:
    const  int dx[8] = {0,1,1,1,0,-1,-1,-1};
    const  int dy[8] = {1,1,0,-1,-1,-1,0,1};
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) 	  {
        if(board[click[0]][click[1]] == 'M'){
            board[click[0]][click[1]] = 'X';
            return board;
        }

        int m = board.size();
        int n= board[0].size();
        queue<pair<int,int>> que;
        que.push(pair<int,int>(click[0],click[1]));
        board[click[0]][click[1]] = 'B';
        while(!que.empty()){
            pair<int,int> top = que.front();
            que.pop();
            int x = top.first;
            int y = top.second;
            int Mnums = 0;
            //判断周围有几个地雷
            for(int i=0;i<8;i++){
                int newx = x+dx[i];
                int newy = y+dy[i];
                if( valid(newx,newy,m,n) && board[newx][newy] == 'M'){
                    Mnums++;
                }
            }

            if(Mnums == 0){
                for(int i=0;i<8;i++){
                    int newx = x+dx[i];
                    int newy = y+dy[i];
                    if( valid(newx,newy,m,n) && board[newx][newy] == 'E'){
                         board[newx][newy] = 'B';
                         que.push(pair<int,int>(newx,newy));
                    }
                }
            }else{
                board[x][y] = Mnums + '0';//转为字符
            }
        }
        return board;
    }
};
```



#### [126. 单词接龙 II](https://leetcode-cn.com/problems/word-ladder-ii/)

> 给定两个单词（*beginWord* 和 *endWord*）和一个字典 *wordList*，找出所有从 *beginWord* 到 *endWord* 的最短转换序列。转换需遵循如下规则：
>
> 1. 每次转换只能改变一个字母。
> 2. 转换后得到的单词必须是字典中的单词。
>
> **说明:**
>
> - 如果不存在这样的转换序列，返回一个空列表。
> - 所有单词具有相同的长度。
> - 所有单词只由小写字母组成。
> - 字典中不存在重复的单词。
> - 你可以假设 *beginWord* 和 *endWord* 是非空的，且二者不相同。
>
> **示例 1:**
>
> ```
> 输入:
> beginWord = "hit",
> endWord = "cog",
> wordList = ["hot","dot","dog","lot","log","cog"]
> 
> 输出:
> [
>   ["hit","hot","dot","dog","cog"],
>   ["hit","hot","lot","log","cog"]
> ]
> ```
>
> **示例 2:**
>
> ```
> 输入:
> beginWord = "hit"
> endWord = "cog"
> wordList = ["hot","dot","dog","lot","log"]
> 
> 输出: []
> 
> 解释: endWord "cog" 不在字典中，所以不存在符合要求的转换序列。
> ```

**解题思路 1 （超时）**

我自己实现的第一版是在  [127. 单词接龙](https://leetcode-cn.com/problems/word-ladder/)  的基础用vector记录每条单词接龙的路径，队列中这时候放的不再是一个单词，而是`vector`。每次取出队列头，查看`vector`的尾元素是否等于`endWord`，决定是否将其`push`到结果集中。

这其中还有个难点就是如何不重复访问单词？

有两种实现方法。一种是全局用一个`visited`的hash表标记单词是否被使用过，但是还需要一个层次的`layerVisited`来标记这个单词在这层被使用过，因为同一层是可以访问相同的单词的，所以在结束这层时，我们才能在visited里真正标记这些单词被访问过。

另外一种方法借鉴 【官方题解】，使用count 数组，`count[word]` 表示 `beginWord` 对应的点到 word 的代价（即转换次数）。初始情况下其所有元素初始化为无穷大。

遍历和它连通的节点（假设为 `to` ）

如果 `cost[to] >=cost[now]+1`  的加入队列，并更新 `cost[to]=cost[now]+1`

如果  `cost[to] < cost[now] + 1` ，说明这个节点已经被访问过，不需要再考虑。

但是这种方法会超时！！！！ 

**解题思路 2 （参考官方题解）**

**代码实现2**

```

```

**解题思路 3 （参考题解 广搜 + 深搜）**



# 第10课 |  贪心算法

## 知识点

**贪心算法 Greedy**

贪心算法是一种在每一步选择中都采取在当前状态下最好或最优（即最有利）的选择，从而希望导致结果是全局最好或最优的算法。 贪心算法与动态规划的不同在于它对每个子问题的解决方案都做出选择，**不能回退**。动态规划则会保存以前的运算结果，并根据以前的结果对当前进行选择，有回退功能。

贪心法可以解决一些最优化问题，如：求图中的最小生成树、求哈夫曼编码等。然而对于工程和生活中的问题，贪心法一般不能得到我们所要求的答案。 一旦一个问题可以通过贪心法来解决，那么贪心法一般是解决这个问题的最好办法。由于贪心法的高效性以及其所求得的答案比较接近最优结果，贪心法也可以用作辅助算法或者直接解决一些要求结果不特别精确的问题。

**适用贪心算法的场景**

简单地说，问题能够分解成子问题来解决，子问题的最优解能递推到最终问题的最优解。这种子问题最优解称为最优子结构。

## 实战题目

#### [860. 柠檬水找零](https://leetcode-cn.com/problems/lemonade-change/)

> 在柠檬水摊上，每一杯柠檬水的售价为 `5` 美元。
>
> 顾客排队购买你的产品，（按账单 `bills` 支付的顺序）一次购买一杯。
>
> 每位顾客只买一杯柠檬水，然后向你付 `5` 美元、`10` 美元或 `20` 美元。你必须给每个顾客正确找零，也就是说净交易是每位顾客向你支付 `5` 美元。
>
> 注意，一开始你手头没有任何零钱。
>
> 如果你能给每位顾客正确找零，返回 `true` ，否则返回 `false` 。
>
> **示例 1：**
>
> ```
> 输入：[5,5,5,10,20]
> 输出：true
> 解释：
> 前 3 位顾客那里，我们按顺序收取 3 张 5 美元的钞票。
> 第 4 位顾客那里，我们收取一张 10 美元的钞票，并返还 5 美元。
> 第 5 位顾客那里，我们找还一张 10 美元的钞票和一张 5 美元的钞票。
> 由于所有客户都得到了正确的找零，所以我们输出 true。
> ```
>
> **示例 2：**
>
> ```
> 输入：[5,5,10]
> 输出：true
> ```
>
> **示例 3：**
>
> ```
> 输入：[10,10]
> 输出：false
> ```
>
> **示例 4：**
>
> ```
> 输入：[5,5,10,10,20]
> 输出：false
> 解释：
> 前 2 位顾客那里，我们按顺序收取 2 张 5 美元的钞票。
> 对于接下来的 2 位顾客，我们收取一张 10 美元的钞票，然后返还 5 美元。
> 对于最后一位顾客，我们无法退回 15 美元，因为我们现在只有两张 10 美元的钞票。
> 由于不是每位顾客都得到了正确的找零，所以答案是 false。
> ```
>
> **提示：**
>
> - `0 <= bills.length <= 10000`
> - `bills[i]` 不是 `5` 就是 `10` 或是 `20` 

**解题思路**

1.用三个变量分别存一下我当前有多少张5元的，多少张10元的，多少找20元的

2.给顾客找零时，优先退还面额最大的，没有再退面额小的 。                                                             

如：顾客给20元，那么需要找零15元。如果我10元和5元的零钱都有，那么就先退一张10元和一张5元；如果没有10元，但是有3张以上的5元，那么就退给顾客3张5元；否则有顾客不能正确找零，返回false

3.注意更新当前每种面额的数目

**代码实现**

```c++
#include<map>
#include<utility>
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int mycash5 = 0;
        int mycash10 = 0;
        int mycash20 = 0;
        int billsLen = bills.size();
        for( int i = 0; i < billsLen ; i++) {
            if ( bills[i] == 5){
                 mycash5++; 
            }else if(bills[i] == 10 ){
                if( mycash5 == 0)
                    return false;
                else{
                    mycash5--;
                    mycash10++;
                }
            }else{
                if( mycash10 != 0 && mycash5 != 0) {//至少一张10元和一张5元
                    mycash10--;
                    mycash5--;
                }else if (mycash5 > 2 ) {//至少有3张5元
                    mycash5 -= 3;
                }else
                    return false;
                mycash20++;
            }
        }
        return true;
    }
};
```



#### [515. 在每个树行中找最大值](https://leetcode-cn.com/problems/find-largest-value-in-each-tree-row/)

> 您需要在二叉树的每一行中找到最大的值。
>
> **示例：**
>
> ```
> 输入: 
> 
>           1
>          / \
>         3   2
>        / \   \  
>       5   3   9 
> 
> 输出: [1, 3, 9]
> ```

**解题思路**

和  [102. 二叉树的层序遍历](https://leetcode-cn.com/problems/binary-tree-level-order-traversal/)   以及 [429. N叉树的层序遍历](https://leetcode-cn.com/problems/n-ary-tree-level-order-traversal/) 的思想、代码基本一样，不同的是，这里记录的是每层的最大值。遍历每层时，依次与当前层最大值比较即可

**代码实现**

```c++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include<queue>
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*> treeQueue;
        vector<int> res;
        if(root == NULL)
            return res;
        treeQueue.push(root);
        while(!treeQueue.empty()) {
            int maxVal = INT_MIN;//每一层都要重置maxVal
            for(int i = treeQueue.size();i > 0;i--) {
                TreeNode* top = treeQueue.front();
                treeQueue.pop();
                if( top->left )
                    treeQueue.push(top->left);
                if( top->right )
                    treeQueue.push(top->right);
                maxVal = top->val > maxVal ? top->val : maxVal;
            }
            res.push_back(maxVal);
        }
        return res;
    }
};
```



#### [322. 零钱兑换](https://leetcode-cn.com/problems/coin-change/)

> 给定不同面额的硬币 coins 和一个总金额 amount。编写一个函数来计算可以凑成总金额所需的最少的硬币个数。如果没有任何一种硬币组合能组成总金额，返回 `-1`。
>
> **示例 1:**
>
> ```
> 输入: coins = [1, 2, 5], amount = 11
> 输出: 3 
> 解释: 11 = 5 + 5 + 1
> ```
>
> **示例 2:**
>
> ```
> 输入: coins = [2], amount = 3
> 输出: -1
> ```

**解题思路 1 （动态规划，迭代，自底向上） **

参考 [官方题解](https://leetcode-cn.com/problems/coin-change/solution/322-ling-qian-dui-huan-by-leetcode-solution/)

事实上这是一道动态规划的题目，最优解可以从其子问题的最优解构造出来。

总金额 `amount` 由 硬币面额 `coins [ c0,c1,.......cn-1]` 组成

设 `Func( amount )`  函数表示组成金额 `amount` 的最少硬币数

如果我们从 `amount` 里减去最后一次加进来的那个硬币面额 c, 那么 `Func(amount - c )  + 1`  代表了组成 `Func( amount )`  的硬币个数。由此可以得到动态转移方程：

​																 `Func(amount - c )  + 1`

这里的  `Func(amount - c )`  可能是   `Func(amount - c0 )` ，  `Func(amount - c1 )`  ，........  `Func(amount - cn-1 )` , 要使得   `Func( amount )`  最小，那么  `Func(amount - c )` 就要取最小

所以可以得到以下递推关系：

- `` Func( amount ) = min F(  amount - ci )``   其中  `0 <= i <=  n-1 && amout-ci >  0`
-  `Func( amount ) = 0`， 当 `` amount = 0`时
-  `Func( amount ) = -1`， 当  `n= 0` 时, 即备选的硬币面额都没有

**示例**

总金额 `amount  = 6` ，`coins = { 1,2,3 } ` , 递归树如下



![img](https://cdn.jsdelivr.net/gh/dekeshile/mycloudimg@master/e0fd2252775b89649ceb6e867ff0e546ec77621edb566693482c8588a98066b8-file_1583404923188)

**代码实现 1**

```c++
/*
    动态规划，自底向上迭代计算
    参考了官方题解，理解了一点再写的
*/
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int MAX = amount +1;
        /*
            dp数组的含义：dp[i] 表示总金额为 i 时，由coins[x ,y ,z,...]能凑成的最少的硬币个数
        */
        vector<int> dp(amount+1,MAX);//数组大小amount+1，初始时数组中每个值都为MAX
        dp[0] = 0;
        //从总金额为1元开始计算，直到总金额为amount
        for(int i=1;i<=amount;i++) {
            //遍历coins数组，对每个总金额 i 来 计算 其 dp[i]
            for(int j = 0; j < coins.size();j++ ) {
                //当前枚举的硬币面额肯定不能大于总金额
                if( coins[j] <= i ){
                /*
                     每枚举到一个硬币面额coin,都和原dp[i]比较，力求dp[i]最小，即硬币个数最小
                     总金额 i-coins[i] 再加上金额coins[i]就达到金额 i ,相应的其硬币数也就是加1
                */
                    dp[i] = min(dp[i],dp[ i-coins[j] ] + 1);
                }
            }
        }
        return ( dp[amount] == MAX ? -1 : dp[amount] );
    }
};
```



# 第11课 | 二分查找

## 知识点

**二分查找的前提**

1. 目标函数单调性（单调递增或者递减）
2. 存在上下界（bounded）
3. 能够通过索引访问（index accessible)

**代码模版**

```python
left, right = 0, len(array) - 1 
while left <= right: 
 mid = (left + right) / 2 
 if array[mid] == target: 
 # find the target!! 
 break or return result 
 elif array[mid] < target: 
 left = mid + 1 
 else: 
 right = mid - 1
```



## 实战题目

#### [153. 寻找旋转排序数组中的最小值](https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/)

> 假设按照升序排序的数组在预先未知的某个点上进行了旋转。
>
> ( 例如，数组 `[0,1,2,4,5,6,7]`  可能变为 `[4,5,6,7,0,1,2]` )。
>
> 请找出其中最小的元素。
>
> 你可以假设数组中不存在重复元素。
>
> **示例 1:**
>
> ```
> 输入: [3,4,5,1,2]
> 输出: 1
> ```
>
> **示例 2:**
>
> ```
> 输入: [4,5,6,7,0,1,2]
> 输出: 0
> ```

**解题思路 **

参考 [官方题解](https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/solution/xun-zhao-xuan-zhuan-pai-lie-shu-zu-zhong-de-zui-xi/)

这题最简单和直观的方法就是遍历一遍数组，初始化一个最小值，然后依次与数组的每个值比较，并更新最小值。

时间复杂度为O(n)。

但是注意到虽然数组被旋转了，从整体上来说并不是有序数组，但是数组分为两半分别有序，所有有可以使用二分查找的空间。

还有以下特点：

- 当数组第一个数小于最后一个数时，数组时有序的，第一个数即是最小的数
- 当   `array[mid - 1] >  array[mid]`  时， `array[mid]` 为最小值
-  或者当 `array[ mid ] > array[mid + 1]` 时，`array[mid + 1]` 为最小值

**代码实现**

```c++
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() -1;
        if(right == 0)
            return nums[left];
        //初始时已经是有序的数组，没有被旋转过
        if(nums[left] < nums[right])
            return nums[left];
        while(left <= right){
            int mid = left + (right - left)/2;
            if(mid+1 <= right && nums[mid] > nums[ mid + 1])
                return nums[ mid + 1];
            if( mid-1 >= 0 && nums[mid -1 ] > nums[mid])
                return nums[mid];
           //左边是含有旋转部分的
            if( nums[0] < nums[mid] ){
                left = mid + 1;
            }else{ //右边是含有旋转部分的
                right = mid - 1;
            }
        }
        return 0;
    }
};
```



#### [33. 搜索旋转排序数组](https://leetcode-cn.com/problems/search-in-rotated-sorted-array/)

> 假设按照升序排序的数组在预先未知的某个点上进行了旋转。
>
> ( 例如，数组 `[0,1,2,4,5,6,7]` 可能变为 `[4,5,6,7,0,1,2]` )。
>
> 搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 `-1` 。
>
> 你可以假设数组中不存在重复的元素。
>
> 你的算法时间复杂度必须是 *O*(log *n*) 级别。
>
> **示例 1:**
>
> ```
> 输入: nums = [4,5,6,7,0,1,2], target = 0
> 输出: 4
> ```
>
> **示例 2:**
>
> ```
> 输入: nums = [4,5,6,7,0,1,2], target = 3
> 输出: -1
> ```

**解题思路**

和 [153. 寻找旋转排序数组中的最小值](https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/)  这题有些相似，数组都是被旋转过的，需要划分区分区间为有序部分和包含旋转的无部分。

参考  [官方题解](https://leetcode-cn.com/problems/search-in-rotated-sorted-array/solution/sou-suo-xuan-zhuan-pai-xu-shu-zu-by-leetcode-solut/) 

对于有序部分，我们用target和这个区间的头尾比较，即可知道 target 是在这个区间，还是在另一个区间，从而收缩 `[ left,right ]`的范围

**代码实现**

```c++
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int len = nums.size();
        if(len == 0)
            return -1;
        if( len == 1)
            return nums[0] == target ?  0 :  -1;
        int right = len -1;      
        while(left <= right){
            int mid = left + ( right -left )/2;
            if( nums[mid] == target)
                return mid;
            // [ left ,mid ] 是有序部分的
            if( nums[left] <= nums[mid] ){
                 if( nums[left] <= target && target < nums[mid] ){
                     right = mid -1;
                 }else{
                     left = mid + 1;
                 }
            }else{//后半部分是有序的
                if( nums[mid] < target && target <= nums[right]){
                    left = mid + 1;
                }else{
                    right = mid -1;
                }
            }
        }
        return -1;
    }
};
```



#### [74. 搜索二维矩阵](https://leetcode-cn.com/problems/search-a-2d-matrix/)

> 编写一个高效的算法来判断 *m* x *n* 矩阵中，是否存在一个目标值。该矩阵具有如下特性：
>
> - 每行中的整数从左到右按升序排列。
> - 每行的第一个整数大于前一行的最后一个整数。
>
> **示例 1:**
>
> ```
> 输入:
> matrix = [
>   [1,   3,  5,  7],
>   [10, 11, 16, 20],
>   [23, 30, 34, 50]
> ]
> target = 3
> 输出: true
> ```
>
> **示例 2:**
>
> ```
> 输入:
> matrix = [
>   [1,   3,  5,  7],
>   [10, 11, 16, 20],
>   [23, 30, 34, 50]
> ]
> target = 13
> 输出: false
> ```

**解题思路**

外层使用二分查找，锁定某一行后，行内再使用二分查找

具体的：

外层以行下标作为 left 和 right ，用 `matrix [mid] [0]`   和 target 比较大小，

- `target  <  matrix [mid] [0]`   则right 向上偏移

- `target  >  matrix [mid] [0]`  , 则还细分为两种

     	  `target  <  matrix [mid] [n-1]`  ，则 target位于 mid 这行，这这行内再使用普通的二分查找即可

  ​          `target  >  matrix [mid] [n-1]`   则 left  向下偏移

**代码实现**

```c++
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int left = 0;
        int right = matrix.size();
        int n;
        if( right != 0 && matrix[0].size() != 0 )
            n = matrix[0].size();
        else
           return false;
        //外部使用二分查找
        while(left < right){
            int mid = left + ( right-left )/2;
            if( matrix[mid][0] == target)
                return true;
            else if( target < matrix[mid][0] ){
                right = mid;
            }else{
                //在这行内部用二分查找
                if(  target <= matrix[mid][n-1] ){
                    int inleft = 0;
                    int inright = n;
                    while(inleft < inright){
                        int inmid = inleft + ( inright-inleft )/2;
                        if( matrix[mid][inmid] == target){
                            return true;
                        }else if(target < matrix[mid][inmid]  ){
                            inright = inmid;
                        }else{
                            inleft = inmid+1;
                        }
                    }
                    return false;
                }else{
                    left = mid + 1;
                }

            }
        }
        return false;
    }
};
```

